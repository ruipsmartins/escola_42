/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:53:49 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/14 16:27:51 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*basin_buffer;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, basin_buffer, 0) < 0)
	{
		ft_zeros(basin_buffer, 'c');
		return (NULL);
	}
	basin_buffer = read_from_file(fd);
	if (basin_buffer == NULL)
		return (NULL);
	return (basin_buffer);
}
