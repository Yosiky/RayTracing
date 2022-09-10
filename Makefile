CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

NAME			=	miniRT

SRC_DIR			=	src
SRC				=	main.c					\
					APIminilibx_one.c

OBJ_DIR			=	obj
OBJ				=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

HEADER_DIR		=	inc
HEADER			=	miniRT.h			\
					APIminilibx.h

MINILIBX_DIR	=	minilibx
MINILIBX		=	libmlx.a

.PHONY:	all clean fclean re

all:	$(OBJ_DIR) $(MINILIBX_DIR)/$(MINILIBX) $(NAME)

$(MINILIBX_DIR)/$(MINILIBX):
	@printf	"Assembling minilibx\n"
	@$(MAKE) -C $(MINILIBX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile						\
				$(addprefix $(HEADER_DIR)/,$(HEADER))		\
				$(MINILIBX_DIR)/$(MINILIBX)
	$(CC) $< -I$(MINILIBX_DIR) -I$(HEADER_DIR) -c -o $@

$(OBJ_DIR):
	mkdir -p $@

$(NAME):	$(addprefix $(HEADER_DIR)/,$(HEADER))		\
			$(OBJ) $(addprefix $(SRC_DIR)/,$(SRC))
	$(CC) $(OBJ) -L$(MINILIBX_DIR) -lmlx -o $@

clean:
	@print "Remove object files\n"
	@rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean clean
