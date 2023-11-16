/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:53:49 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/16 16:58:47 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE +1];
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
	{
		return (NULL);
	}
	new_line = ft_create_line(fd, buffer);
	if (!new_line || !*new_line)
		return (NULL);
	buffer[0] = 0;
	return (new_line);
}
