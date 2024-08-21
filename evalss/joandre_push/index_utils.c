/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:32:44 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/02 03:05:39 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

unsigned int	target_a(t_stack *a, int n)
{
	unsigned int	i;

	i = 1;
	if (n < a->numb && n > last_node(a)->numb)
		i = 0;
	else if (n > max(a) || n < min(a))
		i = index_numb(a, min(a));
	else
	{
		while ((n < a->numb || n > a->next->numb))
		{
			a = a->next;
			++i;
		}
	}
	return (i);
}

unsigned int	target_b(t_stack *b, int n)
{
	unsigned int	i;

	i = 1;
	if (n > b->numb && n < last_node(b)->numb)
		i = 0;
	else if (n > max(b) || n < min(b))
		i = index_numb(b, max(b));
	else
	{
		while (n > b->numb || n < b->next->numb)
		{
			b = b->next;
			++i;
		}
	}
	return (i);
}

unsigned int	index_numb(t_stack *a, int n)
{
	unsigned int	i;

	i = 0;
	while (a->numb != n)
	{
		a = a->next;
		if (a == NULL)
			break ;
		++i;
	}
	return (i);
}

int	numb(t_stack *a, unsigned int i)
{
	while (a->next && i)
	{
		a = a->next;
		--i;
	}
	return (a->numb);
}
