NAME = gitstuff

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = src

SRCS_FILES =	main.c utils.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a


all: $(NAME)
$(LIBFT):
		make -C ./libft


$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@ 

clean:
		rm -f $(OBJS) && make clean -C libft/

fclean: clean
		rm -f $(NAME) && make fclean -C libft/

re: fclean all 

git:
	git add .
	git commit -m "upload github"
	git push
	git status

valgrind:
	valgrind --show-leak-kinds=all --leak-check=full --track-fds=yes --trace-children=yes ./pipex infile "ls -l" "wc -w" outfile


.PHONY: all clean fclean re test git valgrind
