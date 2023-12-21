/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:07:12 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/21 12:55:30 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	int		i;
	char	**numstr;
	int		*intbox;
	t_stack	*a;

	a = NULL;
	a++;
	numstr = ft_split("10 15 -42 98", ' ');
	ft_find_error("10 15 -42 98");

	intbox = malloc(ft_count_words("10 15 -42 98", ' ') * sizeof(int));
	i = 0;
	while (numstr[i])
	{
		intbox[i] = ft_atoi(numstr[i]);
		printf("%i\n", intbox[i]);
		free(numstr[i]);
		i++;
	}
	free(numstr);
	free(intbox);
	return (0);
}
