/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:57:50 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/02 17:24:03 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(long nbr, int base)
{
	char	*symbols;
	int		count;

	symbols = "0123456789abcdef";
	count = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr(-nbr, base) + 1);
	}
	if (nbr < base)
	{
		return (ft_putchar(symbols[nbr]));
	}
	else
	{
		count = ft_putnbr(nbr / base, base);
		return (count + ft_putnbr(nbr % base, base));
	}
}
