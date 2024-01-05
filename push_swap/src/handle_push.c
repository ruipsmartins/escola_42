/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:21:11 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/05 11:44:40 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **x, t_stack **y)
{
	t_stack *temp;
	temp = NULL;
	if (*x == NULL) {
        printf("A pilha de origem está vazia.\n");
        return;
    }
	temp = *x;
	(*x) = (*x)->next;
	if(*x)
		(*x)->prev = NULL;
	temp->next = *y;
	if((*y))
		(*y)->prev = temp;
	(*y) = temp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 4);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 4);
}