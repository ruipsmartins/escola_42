/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtions_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:57:44 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/11 11:58:35 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_nodes(t_stack *stack)
{
	t_stack		*tmp_stack;

	if (stack)
	{
		tmp_stack = stack;
		while (tmp_stack)
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

			tmp_stack = tmp_stack->next;
		}
	}
}

void	ft_print_stacks(t_stack *a, t_stack *b)
{
	printf("\nstack a:\n");
	print_nodes(a);
	printf("\nstack b:\n");
	print_nodes(b);
}

t_stack	*find_last_node(t_stack *stack)
{
	if(!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
