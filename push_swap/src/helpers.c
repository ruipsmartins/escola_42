/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:17:15 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/17 15:47:41 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	check_if_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

int	count_nodes(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_stack	*find_bigger(t_stack *a)
{
	t_stack	*bigger;

	bigger = a;
	while (a)
	{
		if (a->content > bigger->content)
		{
			bigger = a;
		}
		a = a->next;
	}
	return (bigger);
}

t_stack	*find_smaller(t_stack *a)
{
	t_stack	*smaller;

	smaller = a;
	while (a)
	{
		if (a->content < smaller->content)
		{
			smaller = a;
		}
		a = a->next;
	}
	return (smaller);
}
