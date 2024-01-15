/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_reverse_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:07:02 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/15 17:16:53 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse(t_stack **stack)
{
	t_stack	*last_node;

	last_node = find_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack **a)
{
	if (!(*a) || !(*a)->next)
		return ;
	reverse(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	if (!(*b) || !(*b)->next)
		return ;
	reverse(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	if (!(*a) || !(*a)->next)
		return ;
	if (!(*b) || !(*b)->next)
		return ;
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}

void	rev_rotate_both(t_stack **a,
					t_stack **b,
					t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	set_index_median(*a);
	set_index_median(*b);
}
