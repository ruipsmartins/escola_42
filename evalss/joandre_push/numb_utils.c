/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numb_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:50:19 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/02 03:04:32 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

bool	int_check(long long n)
{
	if (n <= INT_MAX && n >= INT_MIN)
		return (true);
	return (false);
}

bool	int_repeat(t_stack *a)
{
	t_stack	*repeat;

	if (a == NULL)
		return (false);
	while (a)
	{
		repeat = a;
		while (repeat)
		{
			if (a != repeat && a->numb == repeat->numb)
				return (true);
			repeat = repeat->next;
		}
		a = a->next;
	}
	return (false);
}

long long	ft_atol(char *a)
{
	long long	n;
	long long	x;

	x = 1;
	if (*a == '-')
	{
		x *= -1;
		++a;
	}
	n = 0;
	while (*a >= '0' && *a <= '9')
	{
		n = n * 10 + (*a - '0');
		++a;
	}
	return (n * x);
}

int	max(t_stack *a)
{
	int	max;

	max = a->numb;
	while (a)
	{
		if (max < a->numb)
			max = a->numb;
		a = a->next;
	}
	return (max);
}

int	min(t_stack *a)
{
	int	min;

	min = a->numb;
	while (a)
	{
		if (min > a->numb)
			min = a->numb;
		a = a->next;
	}
	return (min);
}
