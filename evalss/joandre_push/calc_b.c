/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 03:41:09 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/02 03:29:42 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

unsigned int	calc_b2a_reverse(t_stack *a, t_stack *b, int n)
{
	unsigned int	c;

	c = 0;
	if (index_numb(b, n))
		c = stack_size(b) - index_numb(b, n);
	if (target_a(a, n))
		c += stack_size(a) - target_a(a, n);
	return (c);
}

unsigned int	calc_b2a_rotate(t_stack *a, t_stack *b, int n)
{
	if (index_numb(b, n) >= target_a(a, n))
		return (index_numb(b, n));
	else
		return (target_a(a, n));
}

unsigned int	calc_b2a_rrotate(t_stack *a, t_stack *b, int n)
{
	unsigned int	c;

	c = 0;
	if (index_numb(b, n))
		c = stack_size(b) - index_numb(b, n);
	return (c + target_a(a, n));
}

unsigned int	calc_b2a_rreverse(t_stack *a, t_stack *b, int n)
{
	unsigned int	c;

	c = index_numb(b, n);
	if (target_a(a, n))
		c += stack_size(a) - target_a(a, n);
	return (c);
}

int	cheap_b(t_stack *a, t_stack *b)
{
	int				n;
	unsigned int	p;
	unsigned int	c;
	t_stack			*t;

	n = b->numb;
	p = calc_b2a_reverse(a, b, b->numb);
	t = b;
	while (t)
	{
		c = calc_b2a_reverse(a, b, t->numb);
		if (c > calc_b2a_rotate(a, b, t->numb))
			c = calc_b2a_rotate(a, b, t->numb);
		if (c > calc_b2a_rrotate(a, b, t->numb))
			c = calc_b2a_rrotate(a, b, t->numb);
		if (c > calc_b2a_rreverse(a, b, t->numb))
			c = calc_b2a_rreverse(a, b, t->numb);
		if (p > c)
		{
			p = c;
			n = t->numb;
		}
		t = t->next;
	}
	return (n);
}
