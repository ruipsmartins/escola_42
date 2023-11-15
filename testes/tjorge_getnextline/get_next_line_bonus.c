/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:07:26 by tjorge-d          #+#    #+#             */
/*   Updated: 2023/11/08 17:07:30 by tjorge-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*new_line;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, buffer[fd], 0) < 0)
	{
		ft_zeros(buffer[fd], 'c');
		return (NULL);
	}
	new_line = ft_line_creator(buffer[fd], fd);
	if (new_line == NULL)
		return (NULL);
	return (new_line);
}
