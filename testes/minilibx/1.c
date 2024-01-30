#include <stdlib.h>
#include "mlx_linux/mlx.h"

#define WIDTH 800
#define HEIGHT 500

int main(void)
{
	void	*mlx_connection;
	void	*mlx_window;

	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "my first window");

	for (int y = HEIGHT * 0.1; y < HEIGHT *0.9; y++)
	{
		for (int x = WIDTH * 0.1; x < WIDTH *0.9; x++)
		{
		mlx_pixel_put(mlx_connection, mlx_window, x, y, rand () % 0x1000000);
		}
	}
	mlx_string_put(mlx_connection, mlx_window, WIDTH * 0.8, HEIGHT * 0.95, 0x00ffff, "My pollllllllock");
	mlx_loop(mlx_connection);

	return 0;
}

//cc 1.c ./mlx_linux/libmlx.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o teste