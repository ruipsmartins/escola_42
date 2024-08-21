/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:46:24 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/30 02:47:06 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*create_node(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		new->prev = NULL;
		new->next = NULL;
		new->numb = n;
	}
	return (new);
}

t_stack	*last_node(t_stack *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

unsigned int	stack_size(t_stack *a)
{
	unsigned int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		++i;
	}
	return (i);
}

void	free_stack(t_stack *a)
{
	t_stack	*b;

	while (a)
	{
		b = a;
		a = a->next;
		free(b);
		b = NULL;
	}
}

void	create_stack(t_stack **a, char **n, unsigned int i)
{
	t_stack	*new;
	t_stack	*last;

	if (*n == NULL)
		return ;
	last = create_node(ft_atoi(n[i++]));
	if (last)
	{
		*a = last;
		while (n[i])
		{
			new = create_node(ft_atoi(n[i++]));
			if (new)
			{
				last->next = new;
				new->prev = last;
				last = last->next;
			}
		}
	}
}
