/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:48:11 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/06 15:56:17 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_size(t_data *data)
{
	int	y;

	y = 0;
	data->map_size_x = (ft_strlen(data->map[0]));
	while (data->map[y])
		y++;
	data->map_size_y = y;
}

void	init_game(t_data *data)
{
	data->moves = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map_size_x * 64, data->map_size_y * 64,
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
			"./img/exit_close.xpm", &data->img_width, &data->img_height);
	map_draw(data);
}
