/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:35:07 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/06 15:42:17 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void  flood_fill(char **flooded_map, t_data *data, int player_x, int player_y)
{
/*     if (player_x < 0 || player_y < 0 || player_x >= y || player_y >= x)
        return; */
    if (flooded_map[player_x][player_y] == 'F' || flooded_map[player_x][player_y] == '1')
        return;
	else if (flooded_map[player_x][player_y] == 'C')
		data->c_count ++;
	else if (flooded_map[player_x][player_y] == 'P')
		data->p_count ++;
	else if (flooded_map[player_x][player_y] == 'E')
		data->e_count ++;
    flooded_map[player_x][player_y] = 'F';
	

    flood_fill(flooded_map, data, player_x - 1, player_y);
    flood_fill(flooded_map, data, player_x + 1, player_y);
    flood_fill(flooded_map, data, player_x, player_y - 1);
    flood_fill(flooded_map, data, player_x, player_y + 1);
	return;
}


#include <stdio.h>
#include <stdlib.h>
char **make_flooded_map(char **zone, int _x, int _y)
{
	char **flooded_map;
	flooded_map = (char **)malloc(sizeof(char *) * _y);
	for (int i = 0; i < _y; ++i)
	{
		flooded_map[i] = (char *)malloc(sizeof(char) * _x);
		for (int j = 0; j < _x; ++j)
			flooded_map[i][j] = zone[i][2 * j];
	}
	return (flooded_map);
}

int flood_test(t_data *data)
{
	int player_x;
	int player_y;

	player_x = data->player_x;
	player_y = data->player_y;
	data->c_count = 0;
	data->p_count = 0;
	data->e_count = 0;
	char **flooded_map = make_flooded_map(data->map, data->map_size_x, data->map_size_y);

	flood_fill(flooded_map, data, player_x, player_y);
	for (int y = 0; y < data->map_size_y; y++)
	{
		for (int x = 0; x < data->map_size_x; x++)
		{
			if (x != 0)
				printf(" ");
			printf("%c", flooded_map[y][x]);
		}
			free(flooded_map[y]);
		printf("\n");
	}
	printf("numero de C: %d de E: %d e de P:%d\n", data->c_count, data->e_count, data->p_count);
	free(flooded_map);

	if (data->c_count != data->n_collectables || data->e_count != 1 || data->p_count != 1)
		return 0;

	return (1);
}
