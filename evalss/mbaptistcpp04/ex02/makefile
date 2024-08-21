NAME = noAnimal

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I.
RM = rm -fr

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes \
	./noAnimal

.PHONY: all clean fclean re