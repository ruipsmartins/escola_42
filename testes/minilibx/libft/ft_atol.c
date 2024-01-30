/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:22:02 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/21 16:12:02 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//convert ASCII string to integer.

#include "libft.h"

long	ft_atol(const char *str)
{
	int		i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str [i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

/*  #include <stdio.h>

int	main(void)
{
	int		nbr;
	int		nbr2;
	char	str[] = " \t   -007 8";
	
	nbr = ft_atoi(str);
	nbr2 = atoi(str);
	printf("%d\n", nbr);
	printf("%d\n", nbr2);
	
	return (0);
}  */