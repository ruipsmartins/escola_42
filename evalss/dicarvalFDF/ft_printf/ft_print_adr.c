/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:14:16 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/03 13:52:37 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_adr(void *ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (ft_print_str("(nil)"));
	else
	{
		len += ft_print_str("0x");
		len += ft_print_hexa(((unsigned long int) ptr), 'x');
	}
	return (len);
}
