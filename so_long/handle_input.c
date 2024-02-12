/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:59:29 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/02/10 12:14:49 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keycode, t_mlx_data *data)
{
	int		passada = 40;
	int		xpm1_x;
	int		xpm1_y;

	if (keycode == 65307)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", keycode);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);	
	}

	if (keycode == 115 && data->y < 920)
	{
		data->y += passada;
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./img/boneco_d.xpm", &xpm1_x, &xpm1_y);
	}
	if (keycode == 119 && data->y > 50)
		{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./img/boneco_u.xpm", &xpm1_x, &xpm1_y);
		data->y -= passada;
		}
	if (keycode == 100 && data->x < 920)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./img/boneco_r.xpm", &xpm1_x, &xpm1_y);
		data->x += passada;
	}
	if (keycode == 97 && data->x > 50)
		{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		data->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./img/boneco_l.xpm", &xpm1_x, &xpm1_y);
		data->x -= passada;
		}
	
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, data->x, data->y);
	
	ft_printf("The %d key has been pressed\n\n", keycode);
    return (0);
}