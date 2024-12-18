CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c print_hex.c print_pointer.c print_string.c print_char.c print_int.c print_precent.c
OBJS = $(SRCS:.c=.o)
HEADER = ft_printf.h
NAME = libftprintf.a
all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
