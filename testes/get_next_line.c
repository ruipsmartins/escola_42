/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:53:49 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/15 10:24:30 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*cup_buffer;
	static int	count = 1;

	printf("ft_calloc#[%d]---", count ++);
	cup_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!cup_buffer)
		return (NULL);
	bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(cup_buffer);
		return (NULL);
	}
	return (cup_buffer);
}
