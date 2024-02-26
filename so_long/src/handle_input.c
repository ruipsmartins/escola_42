/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:59:29 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/02/26 19:19:18 by ruidos-s         ###   ########.fr       */
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

/* static void move_player(t_data *data, keycode)
{
int	x;
int	y;


} */
int	handle_input(int keycode, t_data *data)
{
	int		passada = 64;
	int		xpm1_x;
	int		xpm1_y;

	if (keycode == 65307)
		free_all(data);
	//S
	if (keycode == 115)
	{
		data->moves++;
		data->map[1][1] = '0';
		data->map[2][1] = 'P';
		mlx_destroy_image(data->mlx_ptr, data->img_player);
		data->img_player = mlx_xpm_file_to_image(data->mlx_ptr, "./img/boneco_d.xpm", &xpm1_x, &xpm1_y);
	}
	//W
	if (keycode == 119)
		{
		data->moves++;
		mlx_destroy_image(data->mlx_ptr, data->img_player);
		data->img_player = mlx_xpm_file_to_image(data->mlx_ptr, "./img/boneco_u.xpm", &xpm1_x, &xpm1_y);
		data->player_y -= passada;
		}
	//D
	if (keycode == 100)
	{
		data->moves++;
		mlx_destroy_image(data->mlx_ptr, data->img_player);
		data->img_player = mlx_xpm_file_to_image(data->mlx_ptr, "./img/boneco_r.xpm", &xpm1_x, &xpm1_y);
		data->player_x += passada;
	}
	//A
	if (keycode == 97)
		{
		data->moves++;
		mlx_destroy_image(data->mlx_ptr, data->img_player);
		data->img_player = mlx_xpm_file_to_image(data->mlx_ptr, "./img/boneco_l.xpm", &xpm1_x, &xpm1_y);
		data->player_x -= passada;
		}
	ft_printf("\033[2K\r");
	ft_printf("moves: %d", data->moves);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	map_draw(data);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_player, data->player_x, data->player_y);
	//ft_printf("The %d key has been pressed\n\n", keycode);
    return (0);
}
