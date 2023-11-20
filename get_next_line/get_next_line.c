/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:53:49 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/20 13:37:39 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE +1];
	char		*new_line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
	{
		while (i <= BUFFER_SIZE)
			buffer[i++] = 0;
		return (NULL);
	}
	new_line = NULL;
	new_line = ft_create_line(fd, buffer);
	if (!new_line || !*new_line)
		return (NULL);
	return (new_line);
}

 int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("file1.txt", O_RDONLY);
	while (++i)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		printf("|%d: %s", i, line);
		free(line);
	}
	return (0);
}