/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:33:36 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/02 11:46:24 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	int	count1;
	int	count2;

	count1 = 0;
	count2 = 0;
	count1 = printf("printf = %s\n", "hello");
	count2 = ft_printf("ft_printf = %s\n", "hello");
	printf("\ncount1 = %d, count2 = %d\n", count1, count2);
	return (0);
}
