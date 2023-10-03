/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:45:41 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/08/15 17:14:23 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	range;
	int	*arr_num;

	range = max - min;
	i = 0;
	if (min >= max)
		return (NULL);
	arr_num = (int *)malloc(range * sizeof(int));
	while (i < range)
	{
		arr_num[i] = min + i;
		i++;
	}
	return (arr_num);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*arr;
	int	i;
	int	max;
	int	min;

	i = 0;
	min = 20;
	max = 30;
	arr = ft_range(min, max);
	while (i < (max - min))
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
	return (0);
}
*/