
NAME = megaphone

SRCS = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS:=.o)
	$(CC) $(CFLAGS) $(SRCS:=.o) -o $(NAME)
	@echo "\e[0;32m Exercise : \e[1;36m$(NAME)\e[0;32m compiled successfully\e[0m"

clean:
	rm -fr $(SRCS:=.o)
	@echo "\e[0;31m Removed object files.\e[0m"

fclean: clean
	rm -fr $(NAME)
	@echo "\e[0;31m Removed executable \e[1;36m$(NAME)\e[0;31m.\e[0m"

re: fclean $(NAME)

.PHONY: all clean fclean re