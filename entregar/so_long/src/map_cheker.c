/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cheker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:02:55 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/12 14:31:30 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	retangular_check(char **map, t_data *data)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (false);
		i++;
	}
	data->map_size_x = ft_strlen(map[0]);
	data->map_size_y = i;
	return (true);
}

static int	walls_checker(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(map[0]);
	while (map[i])
		i++;
	while (map[0][j])
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (false);
		j++;
	}
	j = 0;
	while (map[j])
	{
		if (map[j][0] != '1' || map[j][len - 1] != '1')
			return (false);
		j++;
	}
	return (true);
}

static int	p_e_c_checker(t_data *data)
{
	int	i;
	int	j;

	data->n_player = 0;
	data->n_exit = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->n_player == 0)
				data->n_player++;
			else if (data->map[i][j] == 'E' && data->n_exit == 0)
				data->n_exit++;
			else if (data->map[i][j] == 'C')
				data->n_collectables++;
			else if (data->map[i][j] != '1' && data->map[i][j] != '0')
				return (false);
			j++;
		}
		i++;
	}
	/* if (!data->n_player || !data->n_exit)
		return (false); */
	return (true);
}
static void error_print(int n, t_data *data)
{
	free_map(data);
	if (n == 1)
		ft_printf("There's an error on the map!\n");
	else if (n == 2)
		ft_printf("Can't catch all the coins or exit.\n");
	else if (n == 3)
		ft_printf("The map must have at least one C.\n");
	exit (1);
}
void	map_checker(t_data *data)
{
	data->n_collectables = 0;
	if (!data->map[0])
		error_print(1,data);
	if (!retangular_check(data->map, data))
		error_print(1, data);
	if (!walls_checker(data->map))
		error_print(1, data);
	if (!p_e_c_checker(data))
		error_print(1, data);
	if (!data->n_player || !data->n_exit)
		error_print(1, data);
/* 	if (!data->map[0] || !retangular_check(data->map, data) 
		|| !walls_checker(data->map) || !p_e_c_checker(data))
		error_print(1, data); */
	window_size(data);
	if (!flood_test(data))
		error_print(2, data);
	if (data->n_collectables < 1)
		error_print(3, data);
}
