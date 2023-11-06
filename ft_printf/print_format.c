/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:34:30 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/06 12:12:54 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(long nbr, int base, int upper)
{
	char	*symbols;
	int		count;

	if (nbr == 0)
		return(ft_putstr("(nil)"));
	symbols = "0123456789abcdef";
	count = 0;
	count += ft_putstr("0x");
	return (count + ft_putnbr(nbr, base, upper));
}

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ap, int), 10, 0);
	else if (specifier == 'u')
		count += ft_putnbr(va_arg(ap, unsigned int), 10, 0);
	else if (specifier == 'x')
		count += ft_putnbr(va_arg(ap, unsigned int), 16, 0);
	else if (specifier == 'X')
		count += ft_putnbr(va_arg(ap, unsigned int), 16, 1);
	else if (specifier == 'p')
		count += ft_putptr(va_arg(ap, unsigned long), 16, 3);
	else if (specifier == '%')
		count += write(1, &specifier, 1);
	return (count);
}
