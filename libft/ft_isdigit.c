/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:56:08 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/16 11:45:00 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//checks for a digit (0 through 9).
int	ft_isdigit(int d)
{
	if (d >= '0' && d <= '9')
	{
		return (1);
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
		printf("%d\n", ft_isdigit('5'));
}
*/