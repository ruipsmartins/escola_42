/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:52:07 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/13 15:22:26 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* static int check_img(void *img)
{

} */

static void exit_and_clear(t_data *data)
{
	ft_printf("erro na imagen W\n");
	//mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	//mlx_destroy_image(data->mlx_ptr, data->img_player);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_map(data);
	exit (1);
}

int check_player_img(t_data *data)
{
	int checker;

	checker = 0;
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/player_w.xpm", &data->img_width, &data->img_height);
	if (!data->img_player)
		exit_and_clear(data);

	mlx_destroy_image(data->mlx_ptr, data->img_player);
	/* 
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/player_a.xpm", &data->img_width, &data->img_height);
	if (!data->img_player)
		checker = 1;
	mlx_destroy_image(data->mlx_ptr, data->img_player);
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/player_s.xpm", &data->img_width, &data->img_height);
	if (!data->img_player)
		checker = 1;
	mlx_destroy_image(data->mlx_ptr, data->img_player);
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/player_d.xpm", &data->img_width, &data->img_height);
	if (!data->img_player)
		checker = 1;
	mlx_destroy_image(data->mlx_ptr, data->img_player); */
	return (checker);
}


/* bool check_ambient_img(t_data *data, bool checker)
{
	

} */


void image_checker(t_data *data)
{
	//check_ambient_img(data, checker);
	check_player_img(data);

}
