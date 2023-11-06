/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:33:36 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/06 11:56:10 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int		count1;
	int		count2;
	char	c;
	char	str[] = "hello";
	int		num;

	c = 'A';
	num = -42;
	count1 = 0;
	count2 = 0;
	count1 = printf("teu_printf --> %%c=%c s=%s, u=%u, x=%x X=%X p=%p\n", c,
			str, num, num, num, &num);
	count2 = ft_printf("meu_printf --> %%c=%c s=%s, u=%u, x=%x X=%X p=%p\n", c, str,
			num, num, num, &num);
	printf("\ncount1 = %d, count2 = %d\n", count1, count2);

	count1 = printf(" NULL %p NULL \n", NULL);
	count2 = ft_printf(" NULL %p NULL \n", NULL);
	printf("\ncount1 = %d, count2 = %d\n", count1, count2);

	return (0);
}
