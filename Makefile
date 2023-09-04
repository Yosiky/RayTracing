CC			=	clang
CFLAGS		=	-Werror -Wextra -Werror
LIB			=

INC_DIR		=	include
INCLUDES	=	rt.h

SRC_DIR		=	src
SRC			=	main.c

OBJ_DIR		=	obj

NAME		=	rt

.PHONY: all clean fclean re

all:	$(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $> $(LIB)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	# rm -rf (
