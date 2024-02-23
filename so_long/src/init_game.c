/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:48:11 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/02/23 16:06:18 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_data *data)
{
	int xpm1_x;
	int xpm1_y;

	data->moves = 0;
	data->x_player = 50;
	data->y_player = 50;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "so_l0ng");
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr, "./img/boneco_d.xpm", &xpm1_x, &xpm1_y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_player, data->x_player, data->y_player);
}
