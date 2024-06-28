NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread #-g -pthread

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

run:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./philo 5 800 60 60 5

.PHONY: all clean fclean re run