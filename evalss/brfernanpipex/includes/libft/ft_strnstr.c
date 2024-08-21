/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:38:57 by brfernan          #+#    #+#             */
/*   Updated: 2024/04/01 23:57:30 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *little, size_t n)
{
	size_t	pos;

	if (!str)
		return (NULL);
	if (!*little)
		return ((char *)str);
	pos = ft_strlen((char *)little);
	while (*str && n-- >= pos)
	{
		if (*str == *little && ft_memcmp(str, little, pos) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
