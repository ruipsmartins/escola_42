/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:57:50 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/06 13:53:33 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	ft_putnbr(long nbr, int base, int upper)
{
	char	*symbols;
	int		count;

	symbols = "0123456789abcdef";
	count = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr(-nbr, base, upper) + 1);
	}
	if (nbr < base)
	{
		if (upper == 1)
			return ((ft_putchar(ft_toupper(symbols[nbr]))));
		return (ft_putchar(symbols[nbr]));
	}
	else
	{
		count = ft_putnbr(nbr / base, base, upper);
		return (count + ft_putnbr(nbr % base, base, upper));
	}
}
