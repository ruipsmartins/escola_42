# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 14:19:42 by ruidos-s          #+#    #+#              #
#    Updated: 2023/10/23 16:20:07 by ruidos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = 	ft_atoi.c  ft_isalnum.c  ft_isalpha.c  ft_isascii.c  ft_isdigit.c  ft_isprint.c\
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
		ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c\
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		
OBJS = $(SRCS:.c=.o)

NAME = libft.a

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c

BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	
fclean: clean
	rm -f $(NAME)
	rm -f ./test*

re: fclean all bonus

bonus:	$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

test: $(SRCS) main.c
	$(CC) $(CFLAGS) $(SRCS) $(BONUS) main.c -o teste_main -lbsd

git:
	git add .
	git commit -m "guardar coisas no github"
	git push
	git status

.PHONY: all clean fclean re test git