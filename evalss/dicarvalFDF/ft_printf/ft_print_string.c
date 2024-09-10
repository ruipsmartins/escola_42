/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:27:59 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/01 14:32:16 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (ft_print_str("(null)"));
	while (*str != '\0')
	{
		len += ft_print_char((int)*str);
		str++;
	}
	return (len);
}
