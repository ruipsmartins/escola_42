/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:14:53 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/13 17:29:51 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


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
		//move_a_to_b(a, b); //Move the cheapest `a` nodes into a sorted stack `b`, until three nodes are left in stack `a`
	}
	small_sort(a);
	set_index_median(*a);
	set_index_median(*b);
}
