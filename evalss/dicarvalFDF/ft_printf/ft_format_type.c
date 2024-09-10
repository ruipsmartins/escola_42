/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:18:23 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/14 10:15:25 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_type(char type, va_list ap)
{
	int	len;

	len = 0;
	if (type == 'c')
		len = ft_print_char(va_arg(ap, int));
	else if (type == 's')
		len = ft_print_str(va_arg(ap, char *));
	else if (type == 'p')
		len = ft_print_adr(va_arg(ap, void *));
	else if (type == 'd' || type == 'i')
		len = ft_print_digit((long)(va_arg(ap, int)));
	else if (type == 'u')
		len = ft_print_digit((long)(va_arg(ap, unsigned int)));
	else if (type == 'x')
		len = ft_print_hexa((long)va_arg(ap, unsigned int), 'x');
	else if (type == 'X')
		len = ft_print_hexa((long)va_arg(ap, unsigned int), 'X');
	else if (type == '%')
		len = ft_print_char(type);
	return (len);
}
