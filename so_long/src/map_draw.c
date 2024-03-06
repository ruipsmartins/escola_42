/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:29:08 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/06 15:48:14 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	img_draw(t_data *data, void *image, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		image, x * 64, y * 64);
}

static void	player_draw(t_data *data, void *image, int x, int y)
{
	data->player_x = x;
	data->player_y = y;
	img_draw(data, image, x, y);
}

void	map_draw(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				img_draw(data, data->img_wall, x, y);
			else if (data->map[y][x] == '0')
				img_draw(data, data->img_ground, x, y);
			else if (data->map[y][x] == 'P')
				player_draw(data, data->img_player, x, y);
			else if (data->map[y][x] == 'C')
				img_draw(data, data->img_collectable, x, y);
			else if (data->map[y][x] == 'E')
				img_draw(data, data->img_exit, x, y);
			x++;
		}
		y++;
	}
}
