/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:20:35 by dicarval          #+#    #+#             */
/*   Updated: 2024/09/09 11:45:50 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_max_min_z(t_data *data, int nb)
{
	if (!data->max_z || nb > data->max_z)
		data->max_z = nb;
	if (!data->min_z || nb < data->min_z)
		data->min_z = nb;
	if (data->range_z < data->max_z - data->min_z)
		data->range_z = data->max_z - data->min_z;
}

static int	*split_atoi(t_data *data, char *line)
{
	char	**split_chars;
	int		*int_array;
	int		i;

	i = 0;
	split_chars = ft_split(line, ' ');
	int_array = malloc(sizeof(int) * data->width);
	if (!int_array)
		malloc_fail(data);
	while (i < data->width)
	{
		int_array[i] = ft_atoi(split_chars[i]);
		ft_max_min_z(data, int_array[i]);
		free(split_chars[i]);
		i++;
	}
	free(split_chars);
	return (int_array);
}

void	map_loading(t_data *data, int fd, int index)
{
	char	*line;

	line = get_next_line(fd);
	data->height++;
	if (line)
		map_loading(data, fd, index + 1);
	else
	{
		data->map_content = malloc(sizeof(int *) * data->height);
		if (!data->map_content)
			malloc_fail(data);
	}
	if (line)
		data->map_content[index] = split_atoi(data, line);
	else
	{
		data->map_content[index] = (int *) line;
	}
	free(line);
}
