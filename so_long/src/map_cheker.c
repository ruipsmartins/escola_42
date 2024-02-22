/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cheker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:02:55 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/02/22 18:24:14 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	retangular_check(char **map)
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
	return (true);
}
static	int	walls_checker(char **map)
{
	int	i;
	int	j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(map[0]);
	while(map[i])
		i++;
	while(map[0][j])
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
	int player;
	int exit;
	int i;
	int j;

	player = 0;
	exit = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && player == 0)
				player++;
			else if (data->map[i][j] == 'E' && exit == 0)
				exit++;
			else if (data->map[i][j] == 'C')
				data->n_collectables++;
			else if(data->map[i][j] != '1' && data->map[i][j] != '0')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	map_checker(t_data *data)
{
	if (retangular_check(data->map))
		ft_printf("é retangular\n");
	if (walls_checker(data->map))
		ft_printf("tem as paredes todas\n");
	if (p_e_c_checker(data))
		ft_printf("tem o p e c todos\n");
	return (0);
}