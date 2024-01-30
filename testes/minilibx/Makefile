
CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRCS = $(wildcard *.c)

all:
	$(CC) $(CFLAGS) $(SRCS) ./mlx_linux/libmlx.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o teste


git:
	git add .
	git commit -m "guardar coisas no github"
	git push
	git status

.PHONY: all clean fclean re test git