/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:07:12 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/04 11:42:56 by ruidos-s         ###   ########.fr       */
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
	//t_stack	*stack_b;

	stack_a = NULL;
	// Perguntar ao pessoal se é para fazer print ao erro ou nao se nao tiver args
	if (argc < 2 || !argv[1][0])
		return (0);
	if (argc >= 2)
		concatenate_and_process_args(&stack_a, argc, argv);
	sa(&stack_a);
	
	//fazer print do que esta no stack a
	printStackInfo(stack_a);

	while(stack_a->next)
	{
		stack_a = stack_a->next;
		free(stack_a->prev); 
	}
	free(stack_a);
	return (0);
}
