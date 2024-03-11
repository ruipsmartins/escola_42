/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:37:54 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/11 11:21:44 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		data.map = open_map(argv[1]);
		if (!data.map)
		{
			ft_printf("Map name or path is incorrect.");
			exit(1);
		}
		map_checker(&data);
		init_game(&data);
		mlx_hook(data.win_ptr, DestroyNotify, NoEventMask, close_game, &data);
		mlx_hook(data.win_ptr, KeyPress, KeyPressMask, handle_input, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
	{
		ft_printf("Invalid number of arguments.\n");
		exit (1);
	}
	return (0);
}
