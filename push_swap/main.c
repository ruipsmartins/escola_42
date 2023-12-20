/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:07:12 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/20 17:08:12 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	int		i;
	char	**argv;
	int		*intbox;

	argv = ft_split("10 15 -42 98", ' ');
	intbox = malloc(ft_count_words("10 15 -42 98", ' ') * sizeof(int));
	i = 0;

	while (argv[i])
	{
		intbox[i] = ft_atoi(argv[i]);
		printf("%i\n", intbox[i]);
		free(argv[i]);
		i++;
	}
	free(argv);
	free(intbox);
	return (0);
}
