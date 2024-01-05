/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:17:15 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/05 17:58:43 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack_info(t_stack *stack)
{
	t_stack		*tmp_stack;

	if (stack)
	{
		tmp_stack = stack;
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
}

void	ft_print_stacks(t_stack *a, t_stack *b)
{
	printf("\nstack a:\n");
	print_stack_info(a);
	printf("\nstack b:\n");
	print_stack_info(b);
}

t_stack	*find_last_node(t_stack *stack)
{
	if(!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_free_stacks(t_stack *a, t_stack *b)
{
	if (a)
	{
		while (a->next)
		{
			a = a->next;
			free(a->prev); 
		}
		free(a);
	}
	if (b)
	{
		while (b->next)
		{
			b = b->next;
			free(b->prev); 
		}
		free(b);
	}
}