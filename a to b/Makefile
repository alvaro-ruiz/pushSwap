SRCS = push_swap.c\
		push_swap_stack_utils.c\
		swap.c\
		rotate.c\
		reverse.c\
		push.c\
		ordena.c\
		calcularcoste.c

OBJS = ${SRCS:.c=.o}
NAME = libpushswap.a
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

run:
	$(CC) $(CFLAGS) -o a push_swap.c -L. -lpushswap