/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:07:27 by tjorge-d          #+#    #+#             */
/*   Updated: 2023/11/15 12:37:44 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
	{
		ft_zeros(buffer, 'c');
		return (NULL);
	}
	new_line = ft_line_creator(buffer, fd);
	if (new_line == NULL)
		return (NULL);
	return (new_line);
}

/* int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("file.txt", O_RDONLY);
	while (++i)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%d: %s", i, line);
		free(line);
	}
	free(line);


	return (0);
} */
