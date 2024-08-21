/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 03:41:09 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/02 03:29:24 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

unsigned int	calc_a2b_reverse(t_stack *a, t_stack *b, int n)
{
	unsigned int	c;

	c = 0;
	if (index_numb(a, n))
		c = stack_size(a) - index_numb(a, n);
	if (target_b(b, n))
		c += stack_size(b) - target_b(b, n);
	return (c);
}

unsigned int	calc_a2b_rotate(t_stack *a, t_stack *b, int n)
{
	if (index_numb(a, n) >= target_b(b, n))
		return (index_numb(a, n));
	else
		return (target_b(b, n));
}

unsigned int	calc_a2b_rrotate(t_stack *a, t_stack *b, int n)
{
	unsigned int	c;

	c = 0;
	if (index_numb(a, n))
		c = stack_size(a) - index_numb(a, n);
	return (c + target_b(b, n));
}

unsigned int	calc_a2b_rreverse(t_stack *a, t_stack *b, int n)
{
	unsigned int	c;

	c = index_numb(a, n);
	if (target_b(b, n))
		c += stack_size(b) - target_b(b, n);
	return (c);
}

int	cheap_a(t_stack *a, t_stack *b)
{
	int				n;
	unsigned int	p;
	unsigned int	c;
	t_stack			*t;

	n = a->numb;
	p = calc_a2b_reverse(a, b, a->numb);
	t = a;
	while (t)
	{
		c = calc_a2b_reverse(a, b, t->numb);
		if (c > calc_a2b_rotate(a, b, t->numb))
			c = calc_a2b_rotate(a, b, t->numb);
		if (c > calc_a2b_rrotate(a, b, t->numb))
			c = calc_a2b_rrotate(a, b, t->numb);
		if (c > calc_a2b_rreverse(a, b, t->numb))
			c = calc_a2b_rreverse(a, b, t->numb);
		if (p > c)
		{
			p = c;
			n = t->numb;
		}
		t = t->next;
	}
	return (n);
}
