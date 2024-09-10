/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:04:43 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/06 14:14:00 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit(long int dgt)
{
	int	len;

	len = 0;
	if (dgt < 0)
	{
		len += ft_print_char('-');
		dgt = -dgt;
	}
	if (dgt > 9)
	{
		len += ft_print_digit(dgt / 10);
		len += ft_print_digit(dgt % 10);
	}
	else
		len += ft_print_char(dgt + 48);
	return (len);
}
