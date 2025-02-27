NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I include

SRCS_DIR = src
SRCS_FILES = main.c init_game.c clean_game.c player.c open_map.c # move_player.c  map_draw.c open_map.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS_DIR = obj
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

LIBFT = ./libs/libft/libft.a
MLX = ./libs/minilibx-linux/libmlx.a -lXext -lX11 -lm -lz

all: $(NAME)

$(LIBFT):
	@echo "🔨 Compiling Libft..."
	@make -C ./libs/libft
	@echo "✅ Libft compiled successfully!"

$(MLX):
	@echo "🔨 Compiling MinilibX..."
	@make -C ./libs/minilibx-linux
	@echo "✅ MinilibX compiled successfully!"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "📂 Created obj directory"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@echo "🚀 Cub3D compiled successfully!"

clean:
	@rm -rf $(OBJS_DIR)
	@make clean -C ./libs/libft
	@make clean -C ./libs/minilibx-linux
	@echo "🧹 Cleaned object files"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libs/libft
	@echo "🗑️ Fully cleaned project"

re: fclean all

git:
	git add .
	git commit -m "enviar para o github"
	git push
	git status

valgrind:
	valgrind --show-leak-kinds=all --leak-check=full ./cub3D

.PHONY: all clean fclean re git valgrind