/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:38:08 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/08/13 15:38:15 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i * i < nb)
		i++;
	if (i * i > nb)
		return (0);
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147483647));
	printf("%d\n", ft_sqrt(100));
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(-100));
	printf("%d\n", ft_sqrt(16));
	return (0);
}*/
