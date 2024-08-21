NAME = pipex

SRCS_DIR = ./srcs
SRCS = pipex.c pipex_aux.c errors.c
OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo $(NAME) ready!

$(LIBFT):
	@echo libft compiling!
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo libft compiled and ready!

clean:
	@rm -f -r $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo objects clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo $(NAME) fclean

re: fclean all

.PHONY: all fclean clean re