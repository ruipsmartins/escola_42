/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:43:47 by brfernan          #+#    #+#             */
/*   Updated: 2024/04/01 23:57:18 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	if (n == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] && i < (n - 1))
	{
		dst[i] = src[i];
		i++;
	}
	if (i < n)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
