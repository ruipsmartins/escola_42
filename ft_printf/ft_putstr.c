/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:33:15 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/06 09:57:21 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the string ’s’ to the given file
descriptor. */
#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		ft_putchar(*s++);
		count++;
	}
	return (count);
}
