TARGET			=	$(shell uname | sed 's/[A-Z]/\L&/g')

CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror 	\
					-pedantic-errors -Wfloat-equal -Wshadow -Wcast-qual -Wconversion -Wsign-conversion
CFLAGS			=	-g -O3 -ffast-math

NAME			=	miniRT

SRC_DIR			=	src
SRC				=	main.c					\
					APIminilibx_one.c		\
					ee_error.c				\
					draw.c					\
					ee_list.c				\
					sphere.c				\
					vector3.c				\
					light.c					\
					objects.c				\
					events.c

OBJ_DIR			=	obj
OBJ				=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

MINILIBX_DIR	=	minilibx_$(TARGET)
MINILIBX		=	libmlx.a

HEADER_DIR		=	inc
MAKE_HEADER		=	$(addprefix -I,$(HEADER_DIR))	\
					$(addprefix -I,$(MINILIBX_DIR))
HEADER			=	miniRT.h			\
					APIminilibx.h		\
					ee_list.h			\
					sphere.h			\
					vector3.h			\
					light.h				\
					objects.h


LIB_linux		=	 -L$(MINILIBX_DIR) -lmlx 			\
					 -L/usr/lib -I$() -lXext -lX11 -lm -lz 

LIB_LDarwin		=	-L$(MINILIBX_DIR) -lmlx				\
					-framework OpenGL					\
					-framework AppKit

.PHONY:	all clean fclean re

all:	$(OBJ_DIR) $(MINILIBX_DIR)/$(MINILIBX) $(NAME)

$(MINILIBX_DIR)/$(MINILIBX):
	@printf	"Assembling minilibx\n"
	@$(MAKE) -C $(MINILIBX_DIR)
	@echo  $(addprefix $(HEADER_DIR)/,$(HEADER))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile						\
				$(addprefix $(HEADER_DIR)/,$(HEADER))		\
				$(MINILIBX_DIR)/$(MINILIBX)
	@printf "create %s\n" $@
	@$(CC) $< $(CFLAGS) $(MAKE_HEADER) -c -o $@

$(OBJ_DIR):
	mkdir -p $@

$(NAME):	$(addprefix $(HEADER_DIR)/,$(HEADER))		\
			$(OBJ) $(addprefix $(SRC_DIR)/,$(SRC))
	$(CC) $(OBJ) $(LIB_$(TARGET)) $(CFLAGS) -o $@

clean:
	@printf "Remove miniRT object files\n"
	@rm -rf $(OBJ_DIR)
	# @printf "Remove minilibx object files\n"
	# @rm -rf $(MINILIBX_DIR)/*.o

fclean: clean
	@printf "Remove minilibx\n"
	# @(MAKE) -C $(MINILIBX_DIR)
	# @rm -rf $(MINILIBX_DIR)/$(MINILIBX)
	@printf "Remove miniRT\n"
	@rm -rf $(NAME)

re: fclean all
