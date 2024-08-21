/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:32:02 by brfernan          #+#    #+#             */
/*   Updated: 2024/04/01 23:57:14 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_length;
	size_t	src_length;

	if (!src)
		return (0);
	src_length = ft_strlen(src);
	dest_length = ft_strlen(dest);
	j = dest_length;
	i = 0;
	if (dest_length < size - 1 && size > 0)
	{
		while (src[i] && dest_length + i < size - 1)
		{
			dest[j] = src[i];
			j++;
			i++;
		}
		dest[j] = 0;
	}
	if (dest_length >= size)
		dest_length = size;
	return (dest_length + src_length);
}
