/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:45:52 by aaires-b          #+#    #+#             */
/*   Updated: 2023/08/17 09:44:08 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= nb / i)
	{
		if ((nb % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	nextnb;

	nextnb = nb + 1;
	if (nb <= 1)
		return (2);
	else if (ft_is_prime(nb))
		return (nb);
	else
	{
		while (ft_is_prime(nextnb) == 0)
		{
			nextnb++;
		}
		return (nextnb);
	}
}
/*
#include <stdio.h>
int main()
{
	int nb = 2147483500;
	
	printf("%d", ft_find_next_prime(nb));
}
*/