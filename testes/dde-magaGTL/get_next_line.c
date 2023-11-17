/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:39:57 by dde-maga          #+#    #+#             */
/*   Updated: 2023/11/17 16:18:53 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i ;

	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		while (i <= BUFFER_SIZE)
			buffer[i++] = '\0';
		return (NULL);
	}
	line = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		ft_clean_buf(buffer);
		if (line[ft_strlen(line) - 1] == '\n')
			return (line);
	}
	return (line);
}
