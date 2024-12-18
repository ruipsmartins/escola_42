#Compiler.

CPP:= c++

#Flags 

CPP_FLAGS:= -Wall -Wextra -Werror -std=c++98

#Sources
SRC:= main.cpp BitcoinExchange.cpp

#Header File.
HEADER:= BitcoinExchange.hpp

#Obj
OBJ:= $(SRC:.cpp=.o)

#Name of the excecutable.

NAME:= btc

all:$(NAME)

$(NAME):$(OBJ) $(HEADER)
	$(CPP) $(CPP_FLAGS) -o $(NAME) $(OBJ)

%.o:%.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all

val:re
	valgrind --show-leak-kinds=all ./$(NAME) input.txt
.PHONY: clean fclean re all