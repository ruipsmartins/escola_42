/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:35 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/02/10 07:29:35 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx_linux/mlx.h"
#include <stdio.h>
#include <X11/keysym.h>
#include <X11/X.h>

#define WIDTH 800
#define HEIGHT 800

typedef struct s_mlx_data
{
    void	*mlx_ptr;
    void	*win_ptr;
	void	*img_ptr;
	int		x;
	int		y;
}               t_mlx_data;


int	handle_input(int keycode, t_mlx_data *data)
{
	int		passada = 20;

	if (keycode == 65307 || keycode == Button3)
	{
		printf("The %d key (ESC) has been pressed\n\n", keycode);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);	
	}

	if (keycode == 115 && data->y < 650)
		data->y += passada;
	if (keycode == 119 && data->y > 50)
		data->y -= passada;
	if (keycode == 100 && data->x < 650)
		data->x += passada;
	if (keycode == 97 && data->x > 50)
		data->x -= passada;
	
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, data->x, data->y);
	


	printf("The %d key has been pressed\n\n", keycode);
    return (0);
}

int handle_mouse( int keycode, t_mlx_data *data)
{
	if (keycode == 3)
	{
		printf("The %d key mouse has been pressed\n\n", keycode);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);	
	}
	return 0;
}

int main(void)
{
	t_mlx_data data;
	int	xpm1_x;
	int	xpm1_y;
	data.x=80;
	data.y=80;
	
	if (!(data.mlx_ptr = mlx_init()))
		return (BadAlloc);
	if (!(data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "my first window")))
	{
		free(data.mlx_ptr);
		return (BadAlloc);
	}

	if (!(data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./img/open.xpm", &xpm1_x, &xpm1_y)))
	{
		printf("erro a abrir a imagem\n");
		exit(1);
	}
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, data.x, data.y);
	//mlx_string_put(data.mlx_ptr, data.win_ptr, WIDTH * 0.8, HEIGHT * 0.95, 0x00ffff, "My polock");
	//mlx_key_hook(data.win_ptr, *handle_input, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, handle_input, &data);
	mlx_hook(data.win_ptr, ButtonPress, ButtonPressMask, handle_input, &data);
	mlx_loop(data.mlx_ptr);
	return 0;
}

//cc 1.c ./mlx_linux/libmlx.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o teste