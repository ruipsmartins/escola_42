/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:02:26 by bruno             #+#    #+#             */
/*   Updated: 2024/04/01 23:57:23 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!s || !f || !str)
		return (0);
	i = 0;
	while (i < (ft_strlen((char *)s)))
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
