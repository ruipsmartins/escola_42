/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-cha <yben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 04:33:35 by yben-cha          #+#    #+#             */
/*   Updated: 2024/12/16 04:33:36 by yben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
