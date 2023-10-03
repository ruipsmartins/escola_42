/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:34:50 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/07/31 11:51:56 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	rest;

	div = *a / *b;
	rest = *a % *b;
	*a = div;
	*b = rest;
}
/*
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = 20;
	b = 7;
	ft_ultimate_div_mod(&a, &b);
	printf("a:%d, b:%d\n", a, b);
	return (0);
}*/
