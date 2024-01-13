/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:31:22 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/13 17:25:30 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void set_index_median(t_stack *node)
{
	int		index;
	int 	median;

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
	t_stack *current_b;
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

void	init_nodes_a(t_stack *a, t_stack *b)
{
	set_index_median(a);
	set_index_median(b);
	set_target_a(a, b);
	//cost_analysis_a(a, b);
	//set_cheapest(a);
}