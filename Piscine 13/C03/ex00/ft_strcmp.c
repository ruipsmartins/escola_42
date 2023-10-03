/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:44:39 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/08/02 10:44:43 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	printf("mine: %d\n", ft_strcmp("aaaaba", "aaaabaaa"));
	printf("lib: %d\n", strcmp("aaaaba", "aaba"));

}*/
