/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:26:14 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/07 18:14:20 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	reverse(t_stack **a, t_stack **b, int n)
{
	while (index_numb(*b, n) && target_a(*a, n))
		rrr(a, b);
	while (index_numb(*b, n))
		rrb(b);
	while (target_a(*a, n))
		rra(a);
	pa(b, a);
}

static void	rotate(t_stack **a, t_stack **b, int n)
{
	while (index_numb(*b, n) && target_a(*a, n))
		rr(a, b);
	while (index_numb(*b, n))
		rb(b);
	while (target_a(*a, n))
		ra(a);
	pa(b, a);
}

static void	rrotate(t_stack **a, t_stack **b, int n)
{
	while (index_numb(*b, n))
		rrb(b);
	while (target_a(*a, n))
		ra(a);
	pa(b, a);
}

static void	rreverse(t_stack **a, t_stack **b, int n)
{
	while (index_numb(*b, n))
		rb(b);
	while (target_a(*a, n))
		rra(a);
	pa(b, a);
}

void	sort_a(t_stack **a, t_stack **b)
{
	int				n;
	unsigned int	c;

	n = cheap_b(*a, *b);
	c = calc_b2a_reverse(*a, *b, n);
	if (c > calc_b2a_rotate(*a, *b, n))
		c = calc_b2a_rotate(*a, *b, n);
	if (c > calc_b2a_rrotate(*a, *b, n))
		c = calc_b2a_rrotate(*a, *b, n);
	if (c > calc_b2a_rreverse(*a, *b, n))
		c = calc_b2a_rreverse(*a, *b, n);
	if (c == calc_b2a_reverse(*a, *b, n))
		reverse(a, b, n);
	else if (c == calc_b2a_rotate(*a, *b, n))
		rotate(a, b, n);
	else if (c == calc_b2a_rrotate(*a, *b, n))
		rrotate(a, b, n);
	else if (c == calc_b2a_rreverse(*a, *b, n))
		rreverse(a, b, n);
}
