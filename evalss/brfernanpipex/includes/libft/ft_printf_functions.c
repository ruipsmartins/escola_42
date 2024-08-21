/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 00:04:49 by bruno             #+#    #+#             */
/*   Updated: 2024/04/12 14:28:18 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_putstr(char *str)
{
	int	i;

	if (!str)
		return (ft_printf_putstr("(null)"));
	i = 0;
	while (str[i])
	{
		ft_printf_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_pointer(size_t pointer)
{
	char	str[25];
	int		i;
	int		len;
	char	*base;

	if (!pointer)
		return (ft_printf_putstr("(nil)"));
	base = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	while (pointer != 0)
	{
		str[i] = base[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	len = i + 2;
	while (i--)
		ft_printf_putchar(str[i]);
	return (len);
}

int	ft_hexa(unsigned int x, char x_or_x)
{
	char	str[25];
	char	*base;
	int		i;
	int		len;

	if (x_or_x == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (x == 0)
		return (ft_printf_putstr("0"));
	while (x != 0)
	{
		str[i] = base [x % 16];
		x = x / 16;
		i++;
	}
	len = i;
	while (i--)
		ft_printf_putchar(str[i]);
	return (len);
}
