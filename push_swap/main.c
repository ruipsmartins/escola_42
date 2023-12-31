/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:07:12 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/09 10:38:10 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	// Perguntar ao pessoal se é para fazer print ao erro ou nao se nao tiver args
	if (argc < 2 || !argv[1][0])
		exit(1);
	if (argc >= 2)
		concatenate_and_process_args(&a, argc, argv);
	//fazer print do que esta no stack a
	 
	
	pb(&a, &b);
	rra(&a);
	pa(&a, &b);
	ra(&a);
/* 	
	sa(&a);
	sb(&b);
	ss(&a, &b);
	pa(&a,&b);
	pb(&a,&b);
	ra(&a); 
	rb(&b);
	rr(&a, &b);
	rra(&a);
	rrb(&b);
	rrr(&a, &b);
	*/


	ft_print_stacks(a, b);
	ft_free_stacks(a, b);
	
	return (0);
}
