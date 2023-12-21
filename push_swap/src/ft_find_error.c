/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:02:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/21 16:32:16 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_find_errors(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != '-' && str[i] != '+')
			ft_print_error();
		if ((str[i] == '-' || str[i] == '+') && (str[i + 1] < '0' || str[i + 1] > '9'))
			ft_print_error();
		i++;
	}
}
