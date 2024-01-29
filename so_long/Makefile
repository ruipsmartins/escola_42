# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 11:11:30 by ruidos-s          #+#    #+#              #
#    Updated: 2024/01/19 14:24:29 by ruidos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRCS =	main.c 
		
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a


all: $(NAME)
$(LIBFT):
		make -C ./libft && make clean -C libft/

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(SRCS) $(LIBFT)  -o so_long 

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME) ./push_swap && make fclean -C libft/

re: fclean all 

.PHONY: all clean fclean re
