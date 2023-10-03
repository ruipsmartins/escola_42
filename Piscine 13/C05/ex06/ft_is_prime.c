/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:16:48 by aaires-b          #+#    #+#             */
/*   Updated: 2023/08/17 09:39:31 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
	{
		return (0);
	}
	while (i <= nb / i)
	{
		if ((nb % i) == 0)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>

int main (void)
{
	printf ("%d\n", ft_is_prime(2));
	printf ("%d\n", ft_is_prime(3));
	printf ("%d\n", ft_is_prime(4));
	printf ("%d\n", ft_is_prime(8));
	printf ("%d\n", ft_is_prime(941));
	printf ("%d\n", ft_is_prime(2147483647));
	return (0);
}
*/