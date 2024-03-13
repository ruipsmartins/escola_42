/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:52:07 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/13 15:55:26 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void exit_and_clear(t_data *data)
{
	ft_printf("There is something wrong with the images\n");
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_map(data);
	exit (1);
}

static void check_player_img(t_data *data)
{
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/player_w.xpm", &data->img_width, &data->img_height);
	if (!data->img_player)
		exit_and_clear(data);
	mlx_destroy_image(data->mlx_ptr, data->img_player);
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/player_a.xpm", &data->img_width, &data->img_height);
	if (!data->img_player)
		exit_and_clear(data);
	mlx_destroy_image(data->mlx_ptr, data->img_player);
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/player_s.xpm", &data->img_width, &data->img_height);
	if (!data->img_player)
		exit_and_clear(data);
	mlx_destroy_image(data->mlx_ptr, data->img_player);
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/player_d.xpm", &data->img_width, &data->img_height);
	if (!data->img_player)
		exit_and_clear(data);
	mlx_destroy_image(data->mlx_ptr, data->img_player);
}

static void check_ambient_img(t_data *data)
{
	data->img_ground = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/fundo.xpm", &data->img_width, &data->img_height);
	if (!data->img_ground)
		exit_and_clear(data);
	mlx_destroy_image(data->mlx_ptr, data->img_ground);
	data->img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/bricksx64.xpm", &data->img_width, &data->img_height);
	if (!data->img_wall)
		exit_and_clear(data);
	mlx_destroy_image(data->mlx_ptr, data->img_wall);
	data->img_collectable = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/gold-coin.xpm", &data->img_width, &data->img_height);
	if (!data->img_collectable)
		exit_and_clear(data);
	mlx_destroy_image(data->mlx_ptr, data->img_collectable);
	data->img_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/exit_close.xpm", &data->img_width, &data->img_height);
	if (!data->img_exit)
		exit_and_clear(data);
	mlx_destroy_image(data->mlx_ptr, data->img_exit);
	data->img_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/exit_open.xpm", &data->img_width, &data->img_height);
	if (!data->img_exit)
		exit_and_clear(data);
	mlx_destroy_image(data->mlx_ptr, data->img_exit);
}

void image_checker(t_data *data)
{
	check_player_img(data);
	check_ambient_img(data);
}
