/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:31:22 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/15 17:15:55 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index_median(t_stack *node)
{
	int	index;
	int	median;

	if (!node)
		return ;
	median = count_nodes(node) / 2;
	index = 0;
	while (node)
	{
		node->index = index++;
		if (index <= median)
			node->above_median = true;
		else
			node->above_median = false;
		node = node->next;
	}
}

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;	

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->content < a->content
				&& current_b->content > best_match_index)
			{
				best_match_index = current_b->content;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_bigger(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = count_nodes(a);
	len_b = count_nodes(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	set_index_median(a);
	set_index_median(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
