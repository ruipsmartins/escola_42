/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:02:31 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/06 14:43:11 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long nbr, int base, int reset)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (reset == 1)
	{
		if (nbr == 0)
			return (ft_putstr("(nil)"));
		count += ft_putstr("0x");
	}
	if (nbr < (unsigned long)base)
	{
		ft_putchar(symbols[nbr]);
		count++;
	}
	else
	{
		count += ft_putptr(nbr / base, base, 0);
		count += ft_putptr(nbr % base, base, 0);
	}
	return (count);
}
