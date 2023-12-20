/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:07:12 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/20 16:12:35 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main (void)
{
	int		i;
	char	**argv;
	int		intbox[20];


	*argv = ft_split("10 15 -42 98", ' ');
	while (argv[i])
	{
	intbox[i] = ft_atoi(argv[i]);
	printf("%i\n", intbox[i]);
	free(argv[i]);
	i++;
	}
	if (argv)
		free(argv);
	
	return (0);
}