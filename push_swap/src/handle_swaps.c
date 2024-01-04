/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_swaps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:29:58 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/04 11:43:49 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **node)
{
	(*node)->prev = (*node)->next->next;
	(*node) = (*node)->next;
	(*node)->next = (*node)->prev;
	(*node)->prev = NULL;
	(*node)->next->next = (*node)->next->prev;
	(*node)->next->prev = (*node)->next;
	(*node)->next->next->prev = (*node)->next;
	(*node)->next->prev = (*node);
}

void	sa(t_stack **a)
{
	if (!(*a)->next)
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	if (!(*b) || !(*b)->next)
		return ;
	swap(b);
	write(1, "sb\n", 3);
}
void	ss(t_stack **a, t_stack **b)
{
	if (!(*a) || !(*a)->next)
		return ;
	if (!(*b) || !(*b)->next)
		return ;
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
