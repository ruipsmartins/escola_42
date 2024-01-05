/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:07:12 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/05 11:36:14 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void printStackInfo(t_stack *stack)
{
    t_stack *tmp_stack = stack;
    while (tmp_stack)
    {
        if (tmp_stack->content)
        {
            printf("----------------------------\n");
            printf("Conteúdo do node: %li\n", tmp_stack->content);
            if (tmp_stack->prev)
                printf("prev: %li\n", tmp_stack->prev->content);
            else
                printf("prev = NULL\n");
            if (tmp_stack->next)
                printf("next: %li\n", tmp_stack->next->content);
            else
                printf("next: NULL\n----------------------------\n");
        }
        tmp_stack = tmp_stack->next;
    }
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	// Perguntar ao pessoal se é para fazer print ao erro ou nao se nao tiver args
	if (argc < 2 || !argv[1][0])
		exit(1);
	if (argc >= 2)
		concatenate_and_process_args(&stack_a, argc, argv);
	//fazer print do que esta no stack a
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	sa(&stack_a);
	sb(&stack_b);
	pa(&stack_a, &stack_b);
	printf("stack a:\n");
	printStackInfo(stack_a);
	printf("stack b:\n");
	printStackInfo(stack_b);

	while(stack_a->next)
	{
		stack_a = stack_a->next;
		free(stack_a->prev); 
	}
	free(stack_a);
	while(stack_b->next)
	{
		stack_b = stack_b->next;
		free(stack_b->prev); 
	}
	free(stack_b);
	return (0);
}
