/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-cha <yben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 04:33:03 by yben-cha          #+#    #+#             */
/*   Updated: 2024/12/16 04:34:46 by yben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	its_formatting(char c)
{
	char	*s;
	int		i;

	s = "duixX%csp";
	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

int	what_function(char c, va_list arg)
{
	if (c == 'd' || c == 'i')
		return (print_int(va_arg(arg, int)));
	else if (c == 'u')
		return (print_u_int(va_arg(arg, unsigned int)));
	else if (c == 'X')
		return (print_hex_upp(va_arg(arg, int)));
	else if (c == 'c')
		return (print_char(va_arg(arg, int)));
	else if (c == 'p')
		return (print_pointer(va_arg(arg, void *)));
	else if (c == '%')
		return (print_percent());
	else if (c == 'x')
		return (print_hex_low(va_arg(arg, int)));
	else if (c == 's')
		return (print_string(va_arg(arg, char *)));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		j;
	int		l;

	if (!s)
		return (-1);
	va_start(args, s);
	j = 0;
	l = 0;
	while (s[j])
	{
		if (s[j] == '%' && its_formatting(s[j + 1]))
		{
			l += what_function(s[j + 1], args);
			j += 2;
		}
		else
		{
			write(1, &s[j++], 1);
			l++;
		}
	}
	return (l);
}
