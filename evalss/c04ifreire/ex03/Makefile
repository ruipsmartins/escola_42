# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 08:20:21 by ifreire-          #+#    #+#              #
#    Updated: 2024/01/29 09:23:00 by ifreire-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				= srcs/main.cpp srcs/AMateria.cpp srcs/Character.cpp \
				srcs/Cure.cpp srcs/MateriaSource.cpp srcs/Ice.cpp

OBJ				= $(SRC:.cpp=.o)

CC				= c++

FLAGS			= -Wall -Werror -Wextra -g -std=c++98

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