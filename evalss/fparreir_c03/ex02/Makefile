NAME = FragTrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 #-fsanitize=address
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
BUILD_DIR = build
INCLUDES = -I.
OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(NAME): $(OBJ)
	@echo "Compiling $@..."
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(INCLUDES)
	@echo "Done!"

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@mkdir -p $(@D)
	@echo "Compiling $@..."
	@$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCLUDES)

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned $(NAME) and object files"

re: fclean all

.PHONY: all clean fclean re