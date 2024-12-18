/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-cha <yben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 04:33:29 by yben-cha          #+#    #+#             */
/*   Updated: 2024/12/16 04:34:28 by yben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int n)
{
	unsigned int	nb;
	char			*base;
	int				l;

	l = 0;
	base = "0123456789";
	if (n < 0)
	{
		l = (int)write(1, "-", 1);
		nb = -n;
	}
	else
		nb = n;
	if (nb >= 10)
	{
		l += print_int(nb / 10);
		write(1, &base[nb % 10], 1);
	}
	else
		write(1, &base[nb], 1);
	return (++l);
}

int	print_u_int(unsigned int nb)
{
	char	*base;
	int		l;

	l = 0;
	base = "0123456789";
	if (nb >= 10)
	{
		l += print_int(nb / 10);
		write(1, &base[nb % 10], 1);
	}
	else
		write(1, &base[nb], 1);
	return (++l);
}
