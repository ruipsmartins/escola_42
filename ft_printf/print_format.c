/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:34:30 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/02 11:46:01 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar_fd(va_arg(ap, int), 1);
	if (specifier == 's')
		count += ft_putstr_fd(va_arg(ap, char *), 1);
	/*if (specifier == 'd')
		count += print_digit(va_arg(ap, int), 10);
	if (specifier == 'x')
		count += print_digit(va_arg(ap, unsigned int), 16); */
	else
		count += write(1, &specifier, 1);
	return (count);
}
