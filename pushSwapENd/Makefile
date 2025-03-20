NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_PATH = lib/
LIBFT = $(LIBFT_PATH)/libft.a

HEADERS = -I $(LIBFT_PATH)

SRCS = main.c\
       push_swap.c\
       push_swap_stack_utils.c\
       push_swap_stack_utils1.c\
       swap.c\
       rotate.c\
       reverse.c\
       push.c\
       ordena.c\
       calcularcoste.c

OBJDIR = obj/
OBJS = $(addprefix $(OBJDIR), $(SRCS:%.c=%.o))  # Corrección en la expansión de OBJS

all : $(LIBFT) $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(HEADERS) -o $(NAME)

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJDIR)
	make -C $(LIBFT_PATH) clean

fclean:
	$(RM) $(OBJDIR) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all
