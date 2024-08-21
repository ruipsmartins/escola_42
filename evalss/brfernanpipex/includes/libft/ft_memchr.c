/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:01:46 by bruno             #+#    #+#             */
/*   Updated: 2024/04/01 23:56:24 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	i = 0;
	p = (char *)s;
	while (i < n)
	{
		if ((unsigned char)p[i] == (unsigned char)c)
			return ((char *)p + i);
		i++;
	}
	return (NULL);
}
