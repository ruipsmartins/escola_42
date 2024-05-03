# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 11:11:30 by ruidos-s          #+#    #+#              #
#    Updated: 2024/02/10 07:27:48 by ruidos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g# -fsanitize=address


SRCS =	main.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

MLX = ./mlx_linux/libmlx.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: $(LIBFT) $(MLX) $(NAME)
$(LIBFT):
		make -C ./libft && make clean -C libft/

$(MLX):
		make -C ./mlx_linux

$(NAME): $(OBJS) $(LIBFT) $(MLX)
		$(CC) $(CFLAGS) $(LIBFT) $(OBJS) $(MLX) -o $@ 

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME) && make fclean -C libft/ && make clean -C ./mlx_linux

re: fclean all 
		make clean && clear
#alterar o make clean e clear

git:
	git add .
	git commit -m "enviar para o github"
	git push
	git status

valgrind:
	valgrind --show-leak-kinds=all --leak-check=full ./so_long

.PHONY: all clean fclean re test git valgrind
