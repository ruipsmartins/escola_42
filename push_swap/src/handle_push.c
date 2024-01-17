/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:21:11 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/17 11:52:20 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **x, t_stack **y)
{
	t_stack	*temp;

	temp = *x;
	(*x) = (*x)->next;
	if (*x)
		(*x)->prev = NULL;
	temp->next = *y;
	if (*y)
		(*y)->prev = temp;
	(*y) = temp;
}

void	pa(t_stack **a, t_stack **b)
{
	if (*b == NULL)
		return ;
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	if (*a == NULL)
		return ;
	push(a, b);
	write(1, "pb\n", 3);
}
