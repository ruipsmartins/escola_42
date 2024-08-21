/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:26:14 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/07 18:15:11 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	reverse(t_stack **a, t_stack **b, int n)
{
	while (index_numb(*a, n) && target_b(*b, n))
		rrr(a, b);
	while (index_numb (*a, n))
		rra(a);
	while (target_b(*b, n))
		rrb(b);
	pb(a, b);
}

static void	rotate(t_stack **a, t_stack **b, int n)
{
	while (index_numb(*a, n) && target_b(*b, n))
		rr(a, b);
	while (index_numb(*a, n))
		ra(a);
	while (target_b(*b, n))
		rb(b);
	pb(a, b);
}

static void	rrotate(t_stack **a, t_stack **b, int n)
{
	while (index_numb(*a, n))
		rra(a);
	while (target_b(*b, n))
		rb(b);
	pb(a, b);
}

static void	rreverse(t_stack **a, t_stack **b, int n)
{
	while (index_numb(*a, n))
		ra(a);
	while (target_b(*b, n))
		rrb(b);
	pb(a, b);
}

void	sort_b(t_stack **a, t_stack **b)
{
	int				n;
	unsigned int	c;

	n = cheap_a(*a, *b);
	c = calc_a2b_reverse(*a, *b, n);
	if (c > calc_a2b_rotate(*a, *b, n))
		c = calc_a2b_rotate(*a, *b, n);
	if (c > calc_a2b_rrotate(*a, *b, n))
		c = calc_a2b_rrotate(*a, *b, n);
	if (c > calc_a2b_rreverse(*a, *b, n))
		c = calc_a2b_rreverse(*a, *b, n);
	if (c == calc_a2b_reverse(*a, *b, n))
		reverse(a, b, n);
	else if (c == calc_a2b_rotate(*a, *b, n))
		rotate(a, b, n);
	else if (c == calc_a2b_rrotate(*a, *b, n))
		rrotate(a, b, n);
	else if (c == calc_a2b_rreverse(*a, *b, n))
		rreverse(a, b, n);
}
