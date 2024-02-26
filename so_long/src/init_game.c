/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:48:11 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/02/26 16:48:26 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void window_size(t_data *data)
{
	int	y;

	y = 0;
	data->map_x = (ft_strlen(data->map[0]) * 64) + 64;
	while (data->map[y])
		y++;
	data->map_y = y * 64 + 64;
}

void	init_game(t_data *data)
{
	int xpm1_x;
	int xpm1_y;

	data->moves = 0;
	window_size(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map_x, data->map_y, "so_l0ng");
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr, "./img/boneco_d.xpm", &xpm1_x, &xpm1_y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_player, data->player_x, data->player_y);
}
