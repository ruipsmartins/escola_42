/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:18:53 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/17 17:06:29 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer. */

int	count_words(char const *str, char c)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			count++;
		i++;
	}
	return (count); 
}

char	**ft_split(char const *s, char c)
{
	char	**box;

	box = (char **)malloc(count_words(s, c));
	if (!box)
		return (NULL);


	return (box);
}
