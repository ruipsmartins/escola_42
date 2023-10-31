# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 16:07:09 by ruidos-s          #+#    #+#              #
#    Updated: 2023/10/31 16:15:54 by ruidos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CFLAGS 	=	-Wall -Wextra -Werror

SRCS	=	ft_printf.c

OBJS 	=	 $(SRCS:.c=.o)



test: $(SRCS) main.c
	$(CC) $(CFLAGS) $(SRCS) main.c -o teste_main -lbsd

git:
	git add .
	git commit -m "enviar coisas para o github"
	git push
	git status

.PHONY: all clean fclean re test git