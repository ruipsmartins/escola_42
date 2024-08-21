/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:53:25 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/02 17:11:50 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

bool	sort_check(t_stack *a)
{
	while (a->next)
	{
		if (a->numb > a->next->numb)
			return (false);
		a = a->next;
	}
	return (true);
}

static void	sort_3(t_stack **a)
{
	t_stack	*mid;

	mid = (*a)->next;
	if (mid->numb > mid->prev->numb)
	{
		if (mid->prev->numb < mid->next->numb)
		{
			sa(a);
			ra(a);
		}
		else
			rra(a);
	}
	else if (mid->prev->numb > mid->next->numb)
	{
		if (mid->numb > mid->next->numb)
		{
			ra(a);
			sa(a);
		}
		else
			ra(a);
	}
	else
		sa(a);
}

static void	sort_order(t_stack **a)
{
	if (index_numb(*a, min(*a)) <= stack_size(*a) / 2)
	{
		while (index_numb(*a, min(*a)))
			ra(a);
	}
	else
	{
		while (index_numb(*a, max(*a)) != stack_size(*a) - 1)
			rra(a);
	}
}

void	sort_algo(t_stack **a)
{
	t_stack	**b;

	if (sort_check(*a))
		return ;
	if (stack_size(*a) == 3)
		sort_3(a);
	else
	{
		b = malloc(sizeof(t_stack));
		if (b == NULL)
			return ;
		*b = NULL;
		while (stack_size(*b) < 2 && stack_size(*a) > 3)
			pb(a, b);
		while (stack_size(*a) > 3)
			sort_b(a, b);
		if (!sort_check(*a))
			sort_3(a);
		while (stack_size(*b))
			sort_a(a, b);
		sort_order(a);
		free(b);
	}
}
