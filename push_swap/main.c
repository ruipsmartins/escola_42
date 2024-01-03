/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:07:12 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/03 17:28:41 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*tmp_stack;
	//t_stack	*stack_b;

	stack_a = NULL;
	// Perguntar ao pessoal se é para fazer print ao erro ou nao se nao tiver args
	/*if (argc < 2 || !argv[1][0])
		ft_print_error();*/
	if (argc >= 2)
		concatenate_and_process_args(&stack_a, argc, argv);
	//fazer print do que esta no stack a
	tmp_stack =  stack_a;
	while (tmp_stack)
	{
		printf("Conteúdo do node: ");
		if (tmp_stack->content)
			{
				printf("%li\n", tmp_stack->content);
				if (tmp_stack->prev)
					printf("prev: %li\n", tmp_stack->prev->content);
				else
					printf("prev = NULL\n");
				if(tmp_stack->next)
					printf("next: %li\n", tmp_stack->next->content);
				else
					printf("next: NULL\n");
				printf("----------------------------\n");
			}
			tmp_stack = tmp_stack->next;
	}

	while(stack_a->next)
	{
		stack_a = stack_a->next;
		free(stack_a->prev); 
	}
	free(stack_a);
	return (0);
}
