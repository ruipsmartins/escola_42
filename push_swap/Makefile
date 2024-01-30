# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 11:11:30 by ruidos-s          #+#    #+#              #
#    Updated: 2024/01/30 14:54:22 by ruidos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRCS = $(wildcard src/*.c)

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a


all: $(LIBFT) $(NAME)

$(LIBFT):
		make -C ./libft && make clean -C libft/

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -g $(OBJS) $(LIBFT) -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME) ./push_swap && make fclean -C libft/

re: fclean all 
		make clean && clear

#alterar o make clean e clear
git:
	git add .
	git commit -m "guardar coisas no github"
	git push
	git status

valgrind:
	valgrind --show-leak-kinds=all --leak-check=full ./push_swap  

.PHONY: all clean fclean re test git valgrind