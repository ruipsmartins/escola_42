/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:35:07 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/11 11:12:07 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **flooded_map, t_data *data, int start_x, int start_y)
{
	if (flooded_map[start_x][start_y] == 'F' ||
		flooded_map[start_x][start_y] == '1')
		return ;
	else if (flooded_map[start_x][start_y] == 'C')
		data->c_count ++;
	else if (flooded_map[start_x][start_y] == 'P')
		data->p_count ++;
	else if (flooded_map[start_x][start_y] == 'E')
	{
		data->e_count ++;
		flooded_map[start_x][start_y] = 'F';
		return ;
	}
	flooded_map[start_x][start_y] = 'F';
	flood_fill(flooded_map, data, start_x - 1, start_y);
	flood_fill(flooded_map, data, start_x + 1, start_y);
	flood_fill(flooded_map, data, start_x, start_y - 1);
	flood_fill(flooded_map, data, start_x, start_y + 1);
	return ;
}

char	**make_flooded_map(char **map, int x, int y, t_data *data)
{
	char	**flooded_map;
	int		i;
	int		j;

	flooded_map = (char **)malloc(sizeof(char *) * y);
	i = 0;
	while (i < y)
	{
		flooded_map[i] = (char *)malloc(sizeof(char) * x);
		j = 0;
		while (j < x)
		{
			flooded_map[i][j] = map[i][j];
			if (map[i][j] == 'P')
			{
				data->player_x = i;
				data->player_y = j;
			}
			j++;
		}
		i++;
	}
	return (flooded_map);
}

int	flood_test(t_data *data)
{
	int		start_x;
	int		start_y;
	int		i;
	char	**flooded_map;

	data->c_count = 0;
	data->p_count = 0;
	data->e_count = 0;
	i = 0;
	flooded_map = make_flooded_map(data->map, data->map_size_x,
			data->map_size_y, data);
	start_x = data->player_x;
	start_y = data->player_y;
	flood_fill(flooded_map, data, start_x, start_y);
	while (i < data->map_size_y)
		free(flooded_map[i++]);
	free(flooded_map);
	if (data->c_count != data->n_collectables || data->e_count != 1
		|| data->p_count != 1)
	{
		ft_printf("Can't catch all the coins or exit.\n");
		return (0);
	}
	return (1);
}
