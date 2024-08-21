/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:35:21 by bruno             #+#    #+#             */
/*   Updated: 2024/04/12 14:26:05 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	format(va_list args, const char format)
{
	int		len;

	len = 0;
	if (format == 'c')
		len += ft_printf_putchar(va_arg(args, int));
	if (format == 's')
		len += ft_printf_putstr(va_arg(args, char *));
	if (format == 'p')
		len += ft_pointer(va_arg(args, size_t));
	if (format == 'd' || format == 'i')
		len += ft_printf_putnbr(va_arg(args, int));
	if (format == 'u')
		len += ft_unsigned_int(va_arg(args, unsigned int));
	if (format == 'x')
		len += ft_hexa(va_arg(args, unsigned int), 'x');
	if (format == 'X')
		len += ft_hexa(va_arg(args, unsigned int), 'X');
	if (format == '%')
		len += ft_printf_putchar('%');
	return (len);
}

static int	is_possible(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	args;

	i = -1;
	len = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			while (!is_possible(POSSIBLE, str[i + 1]))
				i++;
			if (is_possible(POSSIBLE, str[i + 1]))
				len += format(args, str[i++ + 1]);
		}
		else
			len += ft_printf_putchar(str[i]);
	}
	va_end(args);
	return (len);
}
