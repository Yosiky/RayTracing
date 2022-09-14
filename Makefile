CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g		\
					# -pedantic-errors -Wfloat-equal -Wshadow -Wcast-qual -Wconversion -Wsign-conversion

NAME			=	miniRT

SRC_DIR			=	src
SRC				=	main.c					\
					APIminilibx_one.c		\
					ee_error.c				\
					draw.c					\
					ee_list.c				\
					sphere.c				\
					vector3.c

OBJ_DIR			=	obj
OBJ				=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

HEADER_DIR		=	inc
HEADER			=	miniRT.h			\
					APIminilibx.h		\
					ee_list.h			\
					sphere.h			\
					vector3.h

MINILIBX_DIR	=	minilibx
MINILIBX		=	libmlx.a

LIB				=	-L$(MINILIBX_DIR) -lmlx				\
					-framework OpenGL					\
					-framework AppKit

.PHONY:	all clean fclean re

all:	$(OBJ_DIR) $(MINILIBX_DIR)/$(MINILIBX) $(NAME)

$(MINILIBX_DIR)/$(MINILIBX):
	@printf	"Assembling minilibx\n"
	@$(MAKE) -C $(MINILIBX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile						\
				$(addprefix $(HEADER_DIR)/,$(HEADER))		\
				$(MINILIBX_DIR)/$(MINILIBX)
	$(CC) $< $(CFLAGS) -g -I$(MINILIBX_DIR) -I$(HEADER_DIR) -c -o $@

$(OBJ_DIR):
	mkdir -p $@

$(NAME):	$(addprefix $(HEADER_DIR)/,$(HEADER))		\
			$(OBJ) $(addprefix $(SRC_DIR)/,$(SRC))
	$(CC) $(OBJ) $(LIB) $(CFLAGS) -o $@

clean:
	@printf "Remove miniRT object files\n"
	@rm -rf $(OBJ_DIR)
	# @printf "Remove minilibx object files\n"
	# @rm -rf $(MINILIBX_DIR)/*.o

fclean: clean
	@printf "Remove minilibx\n"
	@rm -rf $(MINILIBX_DIR)/$(MINILIBX)
	@printf "Remove miniRT\n"
	@rm -rf $(NAME)

re: fclean all
