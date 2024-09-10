# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 17:05:29 by dicarval          #+#    #+#              #
#    Updated: 2024/09/09 12:07:17 by dicarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_PF = ft_printf.c ft_format_type.c ft_print_char.c ft_print_digit.c \
		ft_print_string.c ft_print_adr.c ft_print_hexa.c \

OBJS_PF	= ${SRCS_PF:.c=.o}
RM		= rm -f
LIBC	= ar -rcs
CC		= cc
FLAGS	= -Wall -Wextra -Werror

all: ${NAME}

%.o: %.c
	@${CC} ${FLAGS} -c $^ -o $@

${NAME}: ${OBJS_PF}
	@${LIBC} ${NAME} ${OBJS_PF}

fclean: clean
	@${RM} ${NAME} $(libft)

clean:
	@${RM} ${OBJS_PF} ${OBJS_LB}

re: fclean all

.PHONY: all clean fclean re .c.o
