#include "rt.h"

#define ASSERT_MSG(cmp, msg)    \
    if (!(cmp)) ee_exit(msg);

void    clear_project(void) {
    scene_clear();
    window_clear();
}

inline char *check_arguments(int argc, char **argv) {
    ASSERT_MSG(argc != ARG_EMPTY, "count argements is zero");
    return (argv);
}

void analize_file(int fd, t_scene_config *arg_ptr_scene_config) {
    uint32_t lights[COUNT_TYPE_LIGHTS];
    uint32_t ojbects[COUNT_TYPE_FIGURES];
    uint32_t texture[COUNT_TYPE_TEXTURES];
    uint32_t start_point;
}

t_scene_config  *parse(const char *arg_ptr_str) {
// open file
// read line from file
// parse line
// init mem
// close file

    int fd;
    t_scene_config  *ptr_scene_config;
    char            *read_line;

    fd = open(arg_ptr_str, O_RDONLY);
    ptr_scene_config = (t_scene_config *)malloc(sizeof(t_scene_config));
    analize_file(fd, ptr_scene_config);
    while (1) {
        read_line = get_next_lien(fd);
        switch (choose_object(read_line)) {
            case ():
            // choose create_object
            break;

            default:
            // todo exit from function
            break;
        }
        free(read_line);
    }
    close(fd);
    return (ptr_scene_config);
}

void draw(void) {
    int x;
    int y;

    while (TRUE) {
        for (y = 0; y < WINDOWS_HIGH; ++y) {
            for (x = 0; x < WINDOWS_WIDTH; ++x) {

            }
        }

    }

}

int main(int argc, char **argv) {
// check main's arguments
// parse scene file
// config window
// run drawing

    char            *ptr_name_file_scene;
    t_scene_config  *ptr_scene_config;
    t_window_config *ptr_window_config;

    set_func_clear_project(clear_project);
    ptr_name_file_scene = check_arguments(argc - 1, argv + 1);
    ptr_scene_config = parse(ptr_name_file_scene);
    set_scene_config(ptr_scene_config);
    ptr_window_config = window_init();
    set_window_config(ptr_window_config);
    draw();
    return (0);
}
