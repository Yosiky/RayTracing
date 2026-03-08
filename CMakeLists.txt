cmake_minimum_required(VERSION 3.20)
project(RayTracing LANGUAGES C CXX ASM)

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin|Linux")
    if($CMAKE_SYSTEM_NAME MATCHES "Darwin")
        set(CMAKE_OSX_ARCHITECTURES "arm64")
        set(CMAKE_C_COMPILER_ID "Clang")
        set(SDL_FRAMEWORK ON)
        set(SDL_EXAMPLES ON)
    endif()
endif()

# Set build keys
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set C standard
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Compiler-specific options
# Generic compiler options for all platforms
add_compile_options(-Wall -Wextra -pedantic)

set(CMAKE_C_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_ASM_FLAGS_RELEASE "-O2")

set(CMAKE_C_FLAGS_DEBUG "-g3 -O0")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
set(CMAKE_ASM_FLAGS_DEBUG "-g3 -O0")

set(CMAKE_C_FLAGS_RELWITHDEBINFO "-g -O2")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -O2")
set(CMAKE_ASM_FLAGS_RELWITHDEBINFO "-g -O2")

# Include SDL2 subproject if it exists
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/submodules/SDL")
    add_subdirectory(submodules/SDL EXCLUDE_FROM_ALL)
else()
    message(FATAL_ERROR "The project doesn't work without SDL3")
endif()

# Add executable
add_executable(${PROJECT_NAME})

add_subdirectory(system)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    include
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    SDL3::SDL3
)

# Enable testing if CTest is available
option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    enable_testing()
    # Add tests here
endif()

if(NOT DEFINED CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX ${CMAKE_BUILD_DIR})
endif()

# add_custom_target(clang-tidy-check
#     clang-tidy -p ${CMAKE_BUILD_DIR}/compile_commands.json
#     --checks=* ${PROJECT_NAME}
#     DEPENDS ${PROJECT_NAME}
# )

# Install rules
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}
)

# Print build configuration info
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C Standard: ${CMAKE_C_STANDARD}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
