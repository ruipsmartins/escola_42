# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 13:58:50 by yohan             #+#    #+#              #
#    Updated: 2025/05/05 13:47:14 by ycantin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01
FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

SRC = main.cpp source/Animal.cpp source/Cat.cpp source/Dog.cpp source/WrongAnimal.cpp source/WrongCat.cpp source/Brain.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(NAME)

fclean: clean
	@rm -f $(NAME)

re: clean all
