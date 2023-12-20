NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
    $(CC) $(CFLAGS) $(OBJS) -L. -lft -o $(NAME)

clean:
    rm -f $(OBJS)

fclean: clean
    rm -f $(NAME)

re: fclean all

test: $(SRCS) $(LIBFT)
    $(CC) $(CFLAGS) $(SRCS) -L. -lft -o teste_main -lbsd

git:
	git add .
	git commit -m "guardar coisas no github"
	git push
	git status

.PHONY: all clean fclean re test git