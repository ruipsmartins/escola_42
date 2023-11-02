# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 16:07:09 by ruidos-s          #+#    #+#              #
#    Updated: 2023/11/02 12:06:58 by ruidos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC 		=	 cc
CFLAGS 	=	-Wall -Wextra -Werror
SRCS	=	ft_printf.c print_format.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c

OBJS 	=	 $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS) bonus
	
fclean: clean
	rm -f $(NAME) ./test*
	
re: fclean all bonus

test: $(SRCS) main.c
	$(CC) $(CFLAGS) $(SRCS) libft.a main.c -o teste_main 

git:
	git add .
	git commit -m "enviar coisas para o github"
	git push
	git status

.PHONY: all clean fclean re test git