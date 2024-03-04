/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:14:38 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/04 14:18:33 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_player(t_data *data, char c)
{
	mlx_destroy_image(data->mlx_ptr, data->img_player);
	if (c == 'w')
		data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/player_w.xpm", &data->img_width, &data->img_height);
	else if (c == 'a')
		data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/player_a.xpm", &data->img_width, &data->img_height);
	else if (c == 's')
		data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/player_s.xpm", &data->img_width, &data->img_height);
	else if (c == 'd')
		data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/player_d.xpm", &data->img_width, &data->img_height);
}


void	move_player_w(t_data *data)
{
	if (data->map[data->player_y - 1][data->player_x] == 'E'
		&& data->n_collectables == 0)
		close_game(data);
	update_player(data, 'w');
	if (data->map[data->player_y - 1][data->player_x] != '1'
		&& data->map[data->player_y - 1][data->player_x] != 'E')
	{
		if (data->map[data->player_y - 1][data->player_x] == 'C')
			data->n_collectables--;
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y - 1][data->player_x] = 'P';
		data->moves++;
		update_exit(data);
	}
}

void	move_player_a(t_data *data)
{
	update_player(data, 'a');
	if (data->map[data->player_y][data->player_x - 1] == 'E'
		&& data->n_collectables == 0)
		close_game(data);
	if (data->map[data->player_y][data->player_x - 1] != '1'
		&& data->map[data->player_y][data->player_x - 1] != 'E')
	{
		if (data->map[data->player_y][data->player_x - 1] == 'C')
			data->n_collectables--;
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y][data->player_x - 1] = 'P';
		data->moves++;
	update_exit(data);
	}
}


void	move_player_s(t_data *data)
{
	if (data->map[data->player_y + 1][data->player_x] == 'E'
		&& data->n_collectables == 0)
		close_game(data);
	update_player(data, 's');
	if (data->map[data->player_y + 1][data->player_x] != '1'
		&& data->map[data->player_y + 1][data->player_x] != 'E')
	{
		if (data->map[data->player_y + 1][data->player_x] == 'C')
			data->n_collectables--;
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y + 1][data->player_x] = 'P';
		data->moves++;
		update_exit(data);
	}
}

void	move_player_d(t_data *data)
{
	if (data->map[data->player_y][data->player_x + 1] == 'E'
		&& data->n_collectables == 0)
		close_game(data);
	update_player(data, 'd');
	if (data->map[data->player_y][data->player_x + 1] != '1'
		&& data->map[data->player_y][data->player_x + 1] != 'E')
	{
		if (data->map[data->player_y][data->player_x + 1] == 'C')
			data->n_collectables--;
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y][data->player_x + 1] = 'P';
		data->moves++;
		update_exit(data);
	}
}
