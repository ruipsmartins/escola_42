/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:00:37 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/08/13 10:44:24 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb < 0)
		return (0);
	if (nb > 0)
	{
		res *= nb * ft_recursive_factorial(nb - 1);
		return (res);
	}
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_recursive_factorial(3));
	return (0);
}*/
