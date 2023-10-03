/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:49:27 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/08/15 17:13:06 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*newstr;

	i = 0;
	newstr = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (src[i])
	{
		newstr[i] = src[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*copia;

	copia = ft_strdup("ola mundo");
	printf("a frase copiada foi \"%s\"\n", copia);
	free(copia);
	return (0);
}
*/