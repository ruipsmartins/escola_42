NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -pthread

SRCS = main.c check_arguments.c utils.c init.c safe_functions.c filo_routines.c start_dinner.c monitor.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re