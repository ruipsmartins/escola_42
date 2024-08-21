/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:44:53 by bruno             #+#    #+#             */
/*   Updated: 2024/04/01 23:56:40 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(str + i) = (unsigned char)c;
		i++;
	}
	return (str);
}
