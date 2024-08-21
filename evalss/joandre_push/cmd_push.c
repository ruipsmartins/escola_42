/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:57:50 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/21 11:35:10 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	cmd_push(t_stack **src, t_stack **dst)
{
	t_stack	*linx;

	if (*src == NULL)
		return ;
	linx = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (linx)
		linx->prev = NULL;
	if (*dst == NULL)
	{
		*dst = linx;
		(*dst)->next = NULL;
	}
	else
	{
		linx->next = *dst;
		(*dst)->prev = linx;
		*dst = linx;
	}
}

void	pa(t_stack **b, t_stack **a)
{
	if (*b == NULL)
		return ;
	cmd_push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	if (*a == NULL)
		return ;
	cmd_push(a, b);
	write(1, "pb\n", 3);
}
/*
int	main(void)
{
	int		numb_a[4] = {3, 1, 4, 8};
	int		numb_b[4] = {-31, 341, 144, 0};
	t_stack	*node_a[4];
	t_stack	*node_b[4];

	for (int i = 0; i < 4; i++)
	{
		node_a[i] = malloc(sizeof(t_stack));
		node_a[i]->numb = numb_a[i];
		node_a[i]->next = NULL;
		node_a[i]->prev = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		node_b[i] = malloc(sizeof(t_stack));
		node_b[i]->numb = numb_b[i];
		node_b[i]->next = NULL;
		node_b[i]->prev = NULL;
	}
	t_stack	*head_a = node_a[0];
	for (int i = 1; i < 4; i++)
	{
		t_stack	*linx = head_a;
		while (linx->next)
			linx = linx->next;
		linx->next = node_a[i];
		if (i > 1)
			linx->prev = node_a[i - 2];
		if (i == 3)
			linx->next->prev = linx;
	}
	t_stack	*head_b = node_b[0];
	for (int i = 1; i < 4; i++)
	{
		t_stack	*linx = head_b;
		while (linx->next)
			linx = linx->next;
		linx->next = node_b[i];
		if (i > 1)
			linx->prev = node_b[i - 2];
		if (i == 3)
			linx->next->prev = linx;
	}
	for (int i = 0; i < 4; i++)
		printf("NODE_A NUMB: [%i]\tADDR: [%p] PREV: [%p] NEXT: [%p]\n",
			node_a[i]->numb, node_a[i], node_a[i]->prev, node_a[i]->next);
	printf("\n");
	for (int i = 0; i < 4; i++)
		printf("NODE_B NUMB: [%i]\tADDR: [%p] PREV: [%p] NEXT: [%p]\n",
			node_b[i]->numb, node_b[i], node_b[i]->prev, node_b[i]->next);
	printf("\n***** COMMAND ***** EXECUTED *****\n");
	pb(node_a, node_b);
	printf("**********************************\n");
	head_a = *node_a;
	while (*node_a)
	{
		printf("NODE_A NUMB: [%i]\tADDR: [%p] PREV: [%p] NEXT: [%p]\n",
			(*node_a)->numb, *node_a, (*node_a)->prev, (*node_a)->next);
		*node_a = (*node_a)->next;
	}
	printf("\n");
	head_b = *node_b;
	while (*node_b)
	{
		printf("NODE_B NUMB: [%i]\tADDR: [%p] PREV: [%p] NEXT: [%p]\n",
			(*node_b)->numb, *node_b, (*node_b)->prev, (*node_b)->next);
		*node_b = (*node_b)->next;
	}
	*node_a = head_a;
	while (*node_a)
	{
		head_a = (*node_a)->next;
		free(*node_a);
		*node_a = head_a;
	}
	*node_b = head_b;
	while (*node_b)
	{
		head_b = (*node_b)->next;
		free(*node_b);
		*node_b = head_b;
	}
	return (0);
}*/
