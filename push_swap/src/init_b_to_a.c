/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:25:06 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/15 17:30:18 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_cheapest(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}

static void	set_target_b(t_stack *a, t_stack *b) //Define a function that sets for the current `a` node, its target node from stack `a`
{
	t_stack	*current_a; //To store the pointer to the current `a` node
	t_stack	*target_node; //To store the pointer of the target node for `b` node
	long	best_match_index; //To store the "closest bigger" number so far

	while (b)
	{
		best_match_index = LONG_MAX; //Set the current best match to the max long
		current_a = a; //Assign the pointer to point to the current `a` node
		while (current_a) //While the pointer is not set to NULL
		{
			if (current_a->content > b->content 
				&& current_a->content < best_match_index) //Check if the `a` node's value is bigger than `b` node, && smaller than the "closest bigger" so far
			{
				best_match_index = current_a->content; //Set the best match as the value in the current `a` node
				target_node = current_a; //Set `b` node's target node pointer to point to the current `a` node
			}
			current_a = current_a->next; //Move to the next `a` node for processing
		}
		if (best_match_index == LONG_MAX) //If the best match value has not changed
			b->target_node = find_smaller(a); //Set `b` node's target node pointer to point to the smallest number in stack `a`
		else
			b->target_node = target_node; //If the best match value has been updated, then we have a target node for the current `b` node
		b = b->next; //Move to the next `b` node for processing
	}
}


void	init_nodes_b(t_stack *a, t_stack *b)
{
	set_index_median(a);
	set_index_median(b);
	set_target_b(a, b);
}