/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:49:32 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/02/21 14:04:39 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *path)
{
	int 	fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("error loading map\n");
	}
	else
	{
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			ft_printf("%s", line);
			free(line);
		}
	}
		
	close(fd);
}