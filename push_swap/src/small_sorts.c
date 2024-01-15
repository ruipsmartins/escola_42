/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:11:20 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/15 17:30:24 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_last_node(t_stack *stack)
{
	if(!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	small_sort(t_stack **a)
{
	t_stack	*bigger_node;

	bigger_node = find_bigger(*a);
	if (*a == bigger_node)
		ra(a);
	else if ((*a)->next == bigger_node)
		rra(a);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}
