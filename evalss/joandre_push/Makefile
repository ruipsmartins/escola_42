# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 21:42:53 by joandre-          #+#    #+#              #
#    Updated: 2024/04/09 13:33:47 by ruidos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT = libft/libft.a
SRC = argv_check.c stack_utils.c numb_utils.c index_utils.c calc_a.c calc_b.c \
	  cmd_push.c cmd_reverse.c cmd_rotate.c cmd_swap.c sort_a.c sort_b.c sort_algo.c
PSWAP_SRC = push_swap.c
BONUS_SRC = bonus/checker.c bonus/ccmd_push.c bonus/ccmd_reverse.c \
			bonus/ccmd_rotate.c bonus/ccmd_swap.c
OBJ = $(SRC:.c=.o)
PSWAP_OBJ = $(PSWAP_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(PSWAP_OBJ)
		$(CC) $(CFLAGS) $(PSWAP_OBJ) $(OBJ) -o $(NAME) -L ./libft -lft
$(LIBFT):
		make -s -C ./libft
		make clean -s -C ./libft

bonus: $(LIBFT) $(OBJ) $(BONUS_OBJ)
		$(CC) $(CFLAGS) $(LIBFT) $(OBJ) $(BONUS_OBJ) -o checker -L ./libft -lft

clean:
		rm -rf $(OBJ) $(PSWAP_OBJ) $(BONUS_OBJ)

fclean: clean
		rm -rf $(NAME) checker
		make fclean -s -C ./libft

re: fclean all
