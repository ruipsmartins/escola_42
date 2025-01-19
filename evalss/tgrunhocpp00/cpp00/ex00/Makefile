NAME = megaphone
COMP = c++
FLAG = -Wall -Werror -Wextra -std=c++98
SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) :
	$(COMP) $(FLAG) $(SRC) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
