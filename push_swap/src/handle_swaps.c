/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_swaps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:29:58 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/03 18:43:16 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **node)
{

	(*node) = (*node)->next;
	(*node)->next = (*node)->prev;
	(*node)->prev = NULL;
	(*node)->next->prev = (*node);
	(*node)->next->next = NULL;

	printf("1º node %li\n", (*node)->content);
}

void	sa(t_stack **a)
{
	if (!(*a) || !(*a)->next)
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
