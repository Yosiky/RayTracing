TARGET			=	$(shell uname | sed 's/[A-Z]/\L&/g')

CC				=	clang
CFLAGS			=
CFLAGS			=	-Wall -Wextra -Werror 	\
					-pedantic-errors -Wfloat-equal -Wshadow -Wcast-qual -Wconversion -Wsign-conversion
CFLAGS			+=	-g
CFLAGS			+=	-O0 -ffast-math

NAME			=	miniRT

SRC_DIR			=	src
SRC				=	main.c					\
					APIminilibx_one.c		\
					draw.c					\
					sphere.c				\
					vector3_func1.c				\
					vector3_func2.c				\
					vector3_func3.c				\
					light.c					\
					objects.c				\
					events.c				\
					plane.c					\
					cylinder.c				\
					parser.c				\
					get_func.c				\
					print_info.c			\
					parser_data.c			\
					create_target.c			\
					camera.c				\
					color_func.c			\
					ft_atof.c

OBJ_DIR			=	obj
OBJ				=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

MINILIBX_DIR	=	minilibx_$(TARGET)
MINILIBX		=	libmlx.a

LIBFT_DIR		=	libft
LIBFT			=	libft.a

HEADER_DIR		=	inc
MAKE_HEADER		=	$(addprefix -I,$(HEADER_DIR))	\
					$(addprefix -I,$(MINILIBX_DIR))	\
					$(addprefix -I,$(LIBFT_DIR))

HEADER			=	miniRT.h			\
					APIminilibx.h		\
					sphere.h			\
					vector3.h			\
					light.h				\
					objects.h			\
					plane.h				\
					constants.h			\
					cylinder.h			\
					parser.h			\
					camera.h			\
					color.h

LIB_linux		=	-L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm -lz 

LIB_LDarwin		=	-L$(MINILIBX_DIR) -lmlx				\
					-framework OpenGL					\
					-framework AppKit

LIB_MLX			=	-L$(LIBFT_DIR) -lft

.PHONY:	all clean fclean re

all:	$(OBJ_DIR) 
	@$(MAKE) -C $(MINILIBX_DIR) 
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) $(NAME)

$(LIBFT_DIR)/$(LIBFT):
	@printf	"Assembling libft\n"
	@$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX_DIR)/$(MINILIBX):
	@printf	"Assembling minilibx\n"
	@$(MAKE) -C $(MINILIBX_DIR)

create_link_on_header:
	ln inc/*.h src/
	ln $(MINILIBX_DIR)/mlx.h src/
	ln $(LIBFT_DIR)/*.h src/

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile						\
				$(addprefix $(HEADER_DIR)/,$(HEADER))		\
				$(MINILIBX_DIR)/$(MINILIBX)
	@printf "create %s\n" $@
	@$(CC) $< $(CFLAGS) $(MAKE_HEADER) -c -o $@

$(OBJ_DIR):
	mkdir -p $@

$(NAME):	$(addprefix $(HEADER_DIR)/,$(HEADER))		\
			$(OBJ) $(addprefix $(SRC_DIR)/,$(SRC))
	$(CC) $(OBJ) $(LIB_MLX) $(LIB_$(TARGET)) $(CFLAGS) -o $@

clean:
	@rm -rf src/*.h
	@printf "Remove miniRT object files\n"
	@rm -rf $(OBJ_DIR)
	@printf "Remove minilibx object files\n"
	@rm -rf $(MINILIBX_DIR)/*.o
	@printf "Remove libft object files\n"
	@rm -rf $(LIBFT_DIR)/*.o

fclean: clean
	@printf "Remove miniRT\n"
	@rm -rf $(NAME)
	@printf "Remove minilibx\n"
	@rm -rf $(MINILIBX_DIR)/$(MINILIBX)
	@printf "Remove libft\n"
	@rm -rf $(LIBFT_DIR)/$(LIBFT)

re: fclean all
