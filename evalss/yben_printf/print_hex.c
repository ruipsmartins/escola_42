/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-cha <yben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 04:33:25 by yben-cha          #+#    #+#             */
/*   Updated: 2024/12/16 04:34:12 by yben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(int n, char *base)
{
	unsigned int	nb;
	int				l;

	l = 0;
	nb = (unsigned int)n;
	if (nb >= 16)
	{
		l += print_hex(nb / 16, base);
		write(1, &base[nb % 16], 1);
	}
	else
		write(1, &base[nb], 1);
	return (++l);
}

int	print_hex_low(int n)
{
	return (print_hex(n, "0123456789abcdef"));
}

int	print_hex_upp(int n)
{
	return (print_hex(n, "0123456789ABCDEF"));
}
