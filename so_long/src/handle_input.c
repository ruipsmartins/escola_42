/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:59:29 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/02/27 11:45:30 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_all(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_player);
	mlx_destroy_image(data->mlx_ptr, data->img_exit);
	mlx_destroy_image(data->mlx_ptr, data->img_collectable);
	mlx_destroy_image(data->mlx_ptr, data->img_ground);
	mlx_destroy_image(data->mlx_ptr, data->img_wall);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_map(data);
	ft_putchar_fd('\n',1);
	exit(0);	
}


int	handle_input(int keycode, t_data *data)
{
	if (keycode == 65307)
		free_all(data);
	else if (keycode == 119)
		move_player_w(data);
	else if (keycode == 97)
		move_player_a(data);
	else if (keycode == 115)
		move_player_s(data);
	else if (keycode == 100)
		move_player_d(data);
	ft_printf("\033[2K\r");
	ft_printf("collectables: %d | moves: %d",data->n_collectables, data->moves);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	map_draw(data);
    return (0);
}
