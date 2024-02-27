/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:48:11 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/02/27 12:25:50 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	window_size(t_data *data)
{
	int	y;

	y = 0;
	data->map_x = (ft_strlen(data->map[0]) * 64);
	while (data->map[y])
		y++;
	data->map_y = y * 64;
}

void	init_game(t_data *data)
{
	data->moves = 0;
	window_size(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map_x, data->map_y,
			"so_long");
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/player_s.xpm", &data->img_width, &data->img_height);
	data->img_ground = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/fundo.xpm", &data->img_width, &data->img_height);
	data->img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/bricksx64.xpm", &data->img_width, &data->img_height);
	data->img_collectable = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/gold-coin.xpm", &data->img_width, &data->img_height);
	data->img_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/exit.xpm", &data->img_width, &data->img_height);
	map_draw(data);
}
