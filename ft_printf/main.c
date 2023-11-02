/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:33:36 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/02 17:29:40 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	int	count1;
	int	count2;

	char	c = 'A';
	char	str[]="hello";
	int		num = -100;

	count1 = 0;
	count2 = 0;
	count1 = printf("teu_printf --> %%c=%c s=%s, d=%d, x=%x\n", c, str, num, num);
	count2 = ft_printf("meu_printf --> %%c=%c s=%s, d=%d, x=%x\n", c, str, num, num);
	printf("\ncount1 = %d, count2 = %d\n", count1, count2);
	return (0);
}
