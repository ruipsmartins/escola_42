# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 11:11:30 by ruidos-s          #+#    #+#              #
#    Updated: 2024/03/13 13:15:32 by ruidos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS_FILES =	main.c handle_input.c open_map.c map_cheker.c init_game.c map_draw.c move_player.c flood_fill.c image_checker.c

SRCS_DIR = src

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS = $(SRCS:.c=.o)

LIBFT = ./libs/libft/libft.a

MLX = ./libs/mlx_linux/libmlx.a -Llibs/mlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)
$(LIBFT):
		make -C ./libs/libft

$(MLX):
		make -C ./libs/mlx_linux

$(NAME): $(OBJS) $(LIBFT) $(MLX)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $@ 

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME) && make fclean -C libs/libft/ && make clean -C ./libs/mlx_linux

re: fclean all 

git:
	git add .
	git commit -m "enviar para o github"
	git push
	git status

valgrind:
	valgrind --show-leak-kinds=all --leak-check=full ./so_long "maps/map.ber"

.PHONY: all clean fclean re test git valgrind