/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:07:12 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/20 15:53:52 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main (void)
{
	int		i;
	char	**box = ft_split("10 15 42 98", ' ');

	while (box[i])
	{
	printf("%s\n",box[i]);
	free(box[i]);
	i++;
	}
	if (box)
		free(box);
	
	return (0);
}