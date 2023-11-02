/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:33:36 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/02 12:14:24 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	int	count1;
	int	count2;

	//char	c = 'A';
	//char	str[]="hello";
	int		num = 1000;

	count1 = 0;
	count2 = 0;
	count1 = printf("teu_printf = %d\n", num);
	count2 = ft_printf("meu_printf = %d\n", num);
	printf("\ncount1 = %d, count2 = %d\n", count1, count2);
	return (0);
}
