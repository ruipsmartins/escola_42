/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:05:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/17 17:05:52 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <ctype.h>

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

int	main(void)
{
	char	*str = " hello world ";
	char	c = ' ';
	char	**splited;
	size_t	i;

	printf("%d\n",count_words(str,c));

	/* splited = ft_split(str, c);
	i = 0;
	while (splited[i])
	{
		printf("%s\n",splited[i]);
		i++;
	}

	free(splited); */
	return (0);
}
