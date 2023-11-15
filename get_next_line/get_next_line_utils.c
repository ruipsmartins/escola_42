/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:25:17 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/15 14:26:36 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	size_t	total;

	total = nmemb * size;
	dest = malloc(total);
	if (!dest)
		return (0);
	while (total--)
		((char *)dest)[total] = '\0';
	return (dest);
}

char	*ft_create_line(int fd, char *buffer)
{
	char	*big;


	return (NULL);
}
