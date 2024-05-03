/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:43:17 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/02 11:47:48 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

float	ft_average(int n, ...)
{
	va_list	ap;
	int		total;
	int		i;

	va_start(ap, n);
	total = 0;
	i = 0;
	while (i < n)
	{
		total += va_arg(ap, int);
		i++;
	}
	return ((float)total / n);
}

int	main(void)
{
	float average_age;

	average_age = ft_average(3, 10, 15, 20);
	printf("the average age of those 3 people is %f\n", average_age);

	return (0);
}