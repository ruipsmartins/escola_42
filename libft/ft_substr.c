/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:00:24 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/13 15:05:31 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	actual_len;
	char	*substring;

	if (s == NULL || start >= strlen(s) || len <= 0)
	{
		return (ft_strdup(""));
	}
	actual_len = 0;
	while (s[start + actual_len] != '\0' && actual_len < len)
		actual_len++;
	substring = (char *)malloc(actual_len + 1);
	if (!substring)
		return (NULL);
	i = 0;
	while (i < actual_len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
