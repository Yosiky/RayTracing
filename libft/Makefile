NAME =		libft.a

SRC =		\
			ft_atoi			\
			ft_bzero		\
			ft_calloc		\
			ft_isalnum		\
			ft_isalpha		\
			ft_isascii		\
			ft_isdigit		\
			ft_isprint		\
			ft_itoa			\
			ft_memchr		\
			ft_memcmp		\
			ft_memcpy		\
			ft_memmove		\
			ft_memset		\
			ft_putchar_fd	\
			ft_putendl_fd	\
			ft_putnbr_fd	\
			ft_putstr_fd	\
			ft_split		\
			ft_strchr		\
			ft_strdup		\
			ft_striteri		\
			ft_strjoin		\
			ft_strlcat		\
			ft_strlcpy		\
			ft_strlen		\
			ft_strmapi		\
			ft_strncmp		\
			ft_strnstr		\
			ft_strrchr		\
			ft_strtrim		\
			ft_substr		\
			ft_tolower		\
			ft_toupper		\
			get_next_line	\
			get_next_line_utils	\
			ee_malloc		\
			ee_error

OBJS_DIR =	objects

.PHONY:		all clean fclean re

OBJ =		${addprefix ${OBJS_DIR}/,${SRC:=.o}}

CFLAGS =	-Wall -Wextra -Werror
#-O3 -ffast-math
CC =		gcc

$(OBJS_DIR)/%.o: %.c		
	${CC} ${CFLAGS} -c $< -o $@

$(NAME):	${OBJS_DIR} ${OBJ}
	@ar cr $@ ${OBJ}
	@ranlib $@

all:		${NAME}

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

clean:
	@rm -rf ${OBJ}

fclean: 	clean
	@rm -rf ${NAME}

re:			\
			fclean	\
			all
