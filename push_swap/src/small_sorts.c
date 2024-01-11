/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:11:20 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/11 11:24:14 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void sort_three(t_stack **a)
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
