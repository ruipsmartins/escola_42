/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:34:30 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/02 18:59:25 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd')
		count += ft_putnbr(va_arg(ap, int), 10, 0);
	else if (specifier == 'x')
		count += ft_putnbr(va_arg(ap, unsigned int), 16, 0);
	else if (specifier == 'X')
		count += ft_putnbr(va_arg(ap, unsigned int), 16, 1);
	else if (specifier == 'p')
	{
		count += ft_putstr("0xf");
		count += ft_putnbr(va_arg(ap, unsigned int), 16, 0);
	}
	else if (specifier == '%')
		count += write(1, &specifier, 1);
	return (count);
}
