/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:34:59 by dicarval          #+#    #+#             */
/*   Updated: 2024/09/05 16:59:01 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_esc_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_close_fdf(data);
	return (0);
}

static void	ft_set_variables(t_data *data)
{
	data->def_angle = DEFAULT_ANG;
	data->z_adapted = 1;
	data->max_x = 0;
	data->max_y = 0;
	data->max_z = 0;
	data->min_z = 0;
	data->range_z = 0;
	data->x_pos = 1;
	data->y_pos = 1;
	data->size_grid = 1;
	data->color = 0x000000FF;
	data->p_rgb = 0;
}

static void	map_config(t_data *data)
{
	int	fd;

	fd = check_map(data);
	ft_set_variables(data);
	map_loading(data, fd, 0);
	map_to_point(data);
	data->img.mlx_img = \
		mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, \
		&data->img.bpp, &data->img.line_len, &data->img.endian);
	data->win = mlx_new_window(data->mlx, \
		W_WIDTH, W_HEIGHT, "FdF - dicarval");
	mlx_hook(data->win, KeyPress, KeyPressMask, handle_esc_press, data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, ft_close_fdf, data);
	draw_image_to_grid(data);
}

int	main(int argc, char **argv)
{
	static t_data	data;

	if (argc == 2)
	{
		data.mlx = mlx_init();
		if (data.mlx == NULL)
			return (MLX_ERROR);
		data.map_num = 1;
		data.map_file = argv;
		map_config(&data);
		mlx_loop(data.mlx);
	}
	else
		perror("Number of arguments isn't correct\n");
	return (0);
}
