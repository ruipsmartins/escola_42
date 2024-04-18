# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 11:11:30 by ruidos-s          #+#    #+#              #
#    Updated: 2024/04/18 14:52:45 by ruidos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = src

SRCS_FILES =	main.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a


all: $(NAME)
$(LIBFT):
		make -C ./libft


$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@ 

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME) && make fclean -C libft/

re: fclean all 

git:
	git add . ..
	git commit -m "upload pipex"
	git push
	git status

valgrind:
	valgrind --show-leak-kinds=all --leak-check=full ./pipex infile "ls -l" "wc -l" outfile

.PHONY: all clean fclean re test git valgrind