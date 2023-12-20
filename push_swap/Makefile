# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 11:11:30 by ruidos-s          #+#    #+#              #
#    Updated: 2023/12/20 12:29:20 by ruidos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		ar rc $(NAME) $(OBJS) 

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME) ./test*

re: fclean all

git:
	git add .
	git commit -m "guardar coisas no github"
	git push
	git status
test:
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(NAME) -o teste 

# trocar de teste para push_swap!

.PHONY: all clean fclean re test git