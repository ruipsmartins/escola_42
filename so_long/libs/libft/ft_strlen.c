/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:00:48 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/26 15:00:05 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strlen() function calculates the length of the string pointed to by s, 
excluding the terminating null byte ('\0'). */
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	int	nbr;

	if (ac == 2)
	{
		nbr = ft_strlen(av[1]);
		printf("a frase tem: %d caracteres\n", nbr);
	}
	return (0);
}
*/