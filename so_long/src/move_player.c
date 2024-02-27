/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:14:38 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/02/27 10:53:48 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	move_player_w(t_data *data)
{
		mlx_destroy_image(data->mlx_ptr, data->img_player);
		data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/player_w.xpm", &data->img_width, &data->img_height);
		data->moves++;
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y - 1][data->player_x] = 'P';
}

void	move_player_a(t_data *data)
{
		mlx_destroy_image(data->mlx_ptr, data->img_player);
		data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/player_a.xpm", &data->img_width, &data->img_height);
		data->moves++;
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y - 1][data->player_x] = 'P';
}

void	move_player_s(t_data *data)
{
		mlx_destroy_image(data->mlx_ptr, data->img_player);
		data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/player_s.xpm", &data->img_width, &data->img_height);
		data->moves++;
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y + 1][data->player_x] = 'P';
}

void	move_player_d(t_data *data)
{
		mlx_destroy_image(data->mlx_ptr, data->img_player);
		data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/player_d.xpm", &data->img_width, &data->img_height);
		data->moves++;
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y - 1][data->player_x] = 'P';
}
