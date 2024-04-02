/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:35:17 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/04/02 11:00:09 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
	int len = 0;
	int *new_arr;
	int i = 0;;

	if (start < end)
		len = end - start + 1;
	else if (start > end)
		len = start - end + 1;

	new_arr = malloc (sizeof(int) * len);
	
	while (i < len)
	{
		if (start < end)
		{
			new_arr[i] = start;
			start++;
			i++;
		}
		else
		{
			new_arr[i] = start;
			start--;
			i++;
		}
		
	}
	return (new_arr);
}


int main(void)
{
	int *arr = ft_range(0, -3);
	int i = 0;
	int len = 6;
	while (i <= len)
	{
		printf("%d,", arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
	return 0;
}