/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:23:43 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/09 09:31:11 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	

	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **a)
{
	if (!(*a) || !(*a)->next)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	if (!(*b) || !(*b)->next)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	if (!(*a) || !(*a)->next)
		return ;
	if (!(*b) || !(*b)->next)
		return ;
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
