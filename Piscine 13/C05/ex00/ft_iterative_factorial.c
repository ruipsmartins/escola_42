/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:26:38 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/08/13 10:34:26 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		res *= nb;
		nb--;
	}
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	int	num;

	num = 5;
	printf("%d! is: %d\n", num, ft_iterative_factorial(num));
	return (0);
}
*/
