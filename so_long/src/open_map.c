/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:49:32 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/02/22 18:39:03 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(t_data *data)
{
	int i;

	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
}

char	**open_map(char *path)
{
	int 	fd;
	char	*line;
	char 	*map_data;
	char	*holder;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("error opening map\n");
		exit (1);
	}
	map_data = ft_strdup("");
	while (true)
	{
 		line = get_next_line(fd);
		if (!line)
			break ;
		holder = map_data;
		map_data = ft_strjoin(holder, line);
		ft_printf("%s", line);
		free(line);
		free(holder);
	}
	map = ft_split(map_data, '\n');
	free(map_data);
	ft_printf("\n");
	close(fd);
	return (map);
}
