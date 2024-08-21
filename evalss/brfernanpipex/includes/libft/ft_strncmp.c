/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:39:34 by brfernan          #+#    #+#             */
/*   Updated: 2024/04/01 23:57:28 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
