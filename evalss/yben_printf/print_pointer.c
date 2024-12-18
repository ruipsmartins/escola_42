/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-cha <yben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 04:33:32 by yben-cha          #+#    #+#             */
/*   Updated: 2024/12/16 04:33:33 by yben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_long(long n, char *base)
{
	int				l;
	unsigned long	nb;

	nb = (unsigned long)n;
	l = 0;
	if (nb >= 16)
	{
		l += print_hex_long(nb / 16, base);
		write(1, &base[nb % 16], 1);
	}
	else
		write(1, &base[nb], 1);
	return (++l);
}

int	print_pointer(void *p)
{
	long	n;
	int		l;

	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	n = (long)(p);
	write(1, "0x", 2);
	l = print_hex_long(n, "0123456789abcdef");
	return (2 + l);
}
