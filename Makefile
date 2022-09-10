CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

NAME			=	miniRT

SRC_DIR			=	src
SRC				=	main.					\
					APIminilibx.c

OBJ_DIR			=	obj
OBJ				=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

HEADER_DIR		=	inc
HEADER			=	miniRT.h			\
					APIminilibx.h

MINILIBX_DIR	=	minilibx
MINILIBX		=	minilibx.a

.PHONY:	all clean fclean re

all:	$(OBJ_DIR) $(NAME)

$(MINILIBX_DIR)/$(MINILIBX):
	@printf	"Assembling minilibx\n"
	@$(MAKE) -C $(MINILIBX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(addprefix $(HEADER_DIR)/,$(HEADER))
	$(CC) $< -I$(HEADER_DIR) -c -o $@

$(NAME):	$(addprefix $(HEADER_DIR)/,$(HEADER))		\
			$(OBJ) $(addprefix $(SRC_DIR)/,$(SRC))
	$(CC) $(OBJ) $(MINILIBX_DIR)/$(MINILIBX) -o $@
