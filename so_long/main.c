/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:37:54 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/02/10 11:51:41 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_mlx_data data;
	int xpm1_x;
	int xpm1_y;
	data.x = 50;
	data.y = 50;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 1000, "so_l0ng");
	data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./img/boneco_d.xpm", &xpm1_x, &xpm1_y);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, data.x, data.y);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, handle_input, &data);
	mlx_loop(data.mlx_ptr);

	return (0);
}
