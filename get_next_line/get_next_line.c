/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:53:49 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/15 14:29:41 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*small_buffer;
	int			nbytes;

	small_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!small_buffer)
		return (NULL);
	nbytes = read(fd, small_buffer, BUFFER_SIZE);
	if (nbytes < 1)
	{
		free(small_buffer);
		return (NULL);
	}
	return (small_buffer);
}
