# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 19:51:20 by ifreire-          #+#    #+#              #
#    Updated: 2023/03/18 20:18:38 by ifreire-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				= srcs/main.cpp srcs/Animal.cpp srcs/Dog.cpp srcs/Cat.cpp \
				srcs/WrongAnimal.cpp srcs/WrongCat.cpp

OBJ				= $(SRC:.cpp=.o)

CC				= c++

FLAGS			= -Wall -Werror -Wextra -g -fsanitize=address -std=c++98

NAME			= a.out

%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

all:			$(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
				rm -f $(OBJ)

fclean: 		clean
				rm -f $(NAME)

re: 			fclean $(NAME)

.PHONY: all clean fclean re