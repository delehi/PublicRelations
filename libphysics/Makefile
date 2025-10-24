NAME = libft.a

PART1 = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strcmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_strndup.c

PART2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

SRCS = ${PART1} ${PART2} ${GNL}

OBJ_DIR = obj/

OBJS = ${SRCS:%.c=${OBJ_DIR}%.o}

# BONUS_OBJS = ${BONUS:.c=.o}
BONUS_OBJS = ${BONUS:%.c=${OBJ_DIR}%.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

all: ${NAME}

${OBJ_DIR}: 
		mkdir -p obj
		mkdir -p obj/gnl

${OBJ_DIR}%.o:%.c  | ${OBJ_DIR}
	${CC} ${CFLAGS} -c $< -o $@ 

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}


bonus: ${OBJS} ${BONUS_OBJS}
			${AR} ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
	rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re