/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:49:57 by dicarval          #+#    #+#             */
/*   Updated: 2024/09/09 11:44:38 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	init_point(int y, int x, int z)
{
	t_point	point;

	point.y = y;
	point.x = x;
	point.z = z;
	return (point);
}

static void	limits_finder(t_point point, t_data *data)
{
	int	x;
	int	y;

	if (data->range_z > 90)
		data->z_adapted = 9;
	if (data->range_z > 900)
		data->z_adapted = 90;
	x = point.x;
	y = point.y;
	if (!data->max_x || x > data->max_x)
		data->max_x = x;
	if (!data->max_y || y > data->max_y)
		data->max_y = y;
}

void	map_to_point(t_data *data)
{
	int	y;
	int	x;

	data->point_map = malloc(sizeof(t_point *) * data->height);
	if (!data->point_map)
		malloc_fail(data);
	y = -1;
	while (data->map_content[++y])
	{
		x = -1;
		data->point_map[y] = malloc(sizeof(t_point) * data->width);
		if (!data->point_map[y])
			malloc_fail(data);
		while (++x < data->width)
		{
			data->point_map[y][x] = init_point(y, x, data->map_content[y][x]);
			limits_finder(data->point_map[y][x], data);
		}
	}
	range_to_zoom(data);
}
