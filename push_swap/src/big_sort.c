/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:14:53 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/15 15:19:26 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack *get_cheapest(t_stack *node)
{
	if(!node)
		return (NULL);
	while (node)
	{
		if(node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}
void	prep_for_push(t_stack **stack,
						t_stack *top_node,
						char stack_name) //Define a function that moves the required node to the top of the stack
{
	while (*stack != top_node) //Check if the required node is not already the first node
	{
		if (stack_name == 'a') //If not, and it is stack `a`, execute the following
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}	
	}
}

static void	min_on_top(t_stack **a) //Define a function that moves the smallest number to the top
{
	while ((*a)->content != find_smaller(*a)->content) //As long as the smallest number is not at the top
	{
		if (find_smaller(*a)->above_median) //Rotate or reverse rotate according to the position of the node on the median
			ra(a);
		else
			rra(a);
	}
}

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if(cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
			&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);

	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(a, b);
}

static void move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa (a, b);
}

void	big_sort(t_stack **a, t_stack **b)
{
	int	len_a;

	
	len_a = count_nodes(*a);
	if (len_a-- > 3 && !check_if_sorted(*a))
		pb(a, b);
	if (len_a-- > 3 && !check_if_sorted(*a))
		pb(a, b);
	while (len_a-- > 3 && !check_if_sorted(*a))
	{
		init_nodes_a(*a, *b); //Iniate all nodes from both stacks
		move_a_to_b(a, b); //Move the cheapest `a` nodes into a sorted stack `b`, until three nodes are left in stack `a`
	}
	small_sort(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index_median(*a);
	min_on_top(a);
}
