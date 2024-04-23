# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 11:11:30 by ruidos-s          #+#    #+#              #
#    Updated: 2024/04/23 10:50:51 by ruidos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = src

SRCS_FILES =	main.c utils.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a


all: $(NAME)
$(LIBFT):
		make -C ./libft


$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@ 

clean:
		rm -f $(OBJS) && make clean -C libft/

fclean: clean
		rm -f $(NAME) && make fclean -C libft/

re: fclean all 

git:
	git add . ..
	git commit -m "upload pipex"
	git push
	git status

valgrind:
	valgrind --track-fds=yes --trace-children=yes ./pipex infile "ls -l" "wc -l" outfile

.PHONY: all clean fclean re test git valgrind