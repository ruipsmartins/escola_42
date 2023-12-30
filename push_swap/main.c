/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:07:12 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/30 16:35:10 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*tmp;
	//t_stack	*stack_b;

	stack_a = NULL;
	if (argc < 2 || !argv[1][0])
		ft_print_error();
	if (argc >= 2)
		concatenate_and_process_args(&stack_a, argc, argv);
	//fazer print do que esta no stack a
	while (stack_a)
	{
		printf("Conteúdo do node: ");
		tmp =  stack_a;
		stack_a = stack_a->next;
		if (tmp->content)
			printf("%li\n", tmp->content);
		free(tmp);
	}
	free(stack_a);
	return (0);
}
