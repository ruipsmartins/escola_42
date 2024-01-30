/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:07:12 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/30 14:42:19 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(1);
	if (argc >= 2)
		concatenate_and_process_args(&a, argc, argv);
	if (!check_if_sorted(a))
	{
		if (count_nodes(a) <= 3)
			small_sort(&a);
		else
			big_sort(&a, &b);
	}
	ft_free_stacks(a, b);
	return (0);
}
//Perguntar ao pessoal se é para fazer print ao erro ou nao se nao tiver args
//ARG="5 -3 42 7 8 654 41 -55"; ./teste $ARG | ./checker_linux $ARG