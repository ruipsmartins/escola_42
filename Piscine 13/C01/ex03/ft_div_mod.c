/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:47:00 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/07/31 11:28:18 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*#include <stdio.h>

int	main (void)
{
	int	x;
	int	y;
	ft_div_mod(20,7,&x,&y);
	printf("int:%d, resto:%d\n", x, y);
	return (0);
}*/
