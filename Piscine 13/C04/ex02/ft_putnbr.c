/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:57:39 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/08/06 14:57:43 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nbl;
	char	c[10];
	short	i;

	nbl = nb;
	i = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (nb < 0)
	{
		nbl *= -1;
		ft_putchar('-');
	}
	while (nbl % 10 != 0 || nbl / 10)
	{
		c[i++] = (nbl % 10) + 48;
		nbl /= 10;
	}
	while (i > 0)
	{
		ft_putchar(c[--i]);
	}
}

#include <limits.h>
int	main(void)
{
	int	n1 = 12300;
	int	n2 = -98765;
	int	n3 = INT_MIN;
	int	n4 = INT_MAX;
	int	n5 = 0;

	ft_putnbr(n1);
	ft_putchar('\n');
	ft_putnbr(n2);
	ft_putchar('\n');
	ft_putnbr(n3);
	ft_putchar('\n');
	ft_putnbr(n4);
	ft_putchar('\n');
	ft_putnbr(n5);
	ft_putchar('\n');
	return (0);
}
