#Compiler.

CPP:= c++

#Flags 

CPP_FLAGS:= -Wall -Wextra -Werror -std=c++98

#Sources
SRC:= main.cpp RPN.cpp

#Header File.
HEADER:= RPN.hpp

#Obj
OBJ:= $(SRC:.cpp=.o)

#Name of the excecutable.

NAME:= RPN

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

.PHONY: clean fclean re all