/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:40:49 by bruno             #+#    #+#             */
/*   Updated: 2024/04/06 00:06:51 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
	{
	size_t	i;
	char	*d;
	char	*s;

	if (!src)
		return (NULL);
	if (dest == src || !n)
		return (dest);
	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if (dest > src)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
