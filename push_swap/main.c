/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:07:12 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/21 15:45:22 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	char	**numstr;
	int		*intbox;
	t_stack	*a;

	if (argc < 2 || !argv[1][0])
		ft_print_error();
	
	a = NULL;
	a++;
	numstr = ft_split(argv[1], ' ');
	ft_find_error(argv[1]);

	intbox = malloc(ft_count_words(argv[1], ' ') * sizeof(int));
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
