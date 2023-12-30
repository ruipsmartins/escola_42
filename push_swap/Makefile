# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 11:11:30 by ruidos-s          #+#    #+#              #
#    Updated: 2023/12/30 14:17:38 by ruidos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard src/*.c) main.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a


all: $(NAME)
$(LIBFT):
		make -C ./libft && make clean -C libft/
$(NAME): $(OBJS) $(LIBFT)
		ar rc $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME) ./test* && make fclean -C libft/

re: fclean all 
		make clean && clear
#alterar o make clean e clear
git:
	git add .
	git commit -m "guardar coisas no github"
	git push
	git status

test:
	$(CC) $(CFLAGS) -g $(SRCS) $(LIBFT) $(NAME) -o teste 

valgrind:
	valgrind --leak-check=full ./teste "45 78" 35 " -586 -8" 775

# trocar de teste para push_swap!

.PHONY: all clean fclean re test git valgrind