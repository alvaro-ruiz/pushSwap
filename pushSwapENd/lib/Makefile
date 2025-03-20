SRCS = ft_atoi.c\
		ft_bzero.c\
		ft_split.c\
		ft_calloc.c\
		ft_strlen.c\
		ft_memset.c

OBJS = ${SRCS:.c=.o}
NAME = libft.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror


all: ${NAME}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS} ${OBJSB}

fclean: clean
	rm -f $(NAME)

re: fclean all