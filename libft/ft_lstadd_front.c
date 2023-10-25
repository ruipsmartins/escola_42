/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:53:51 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/25 10:28:48 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* SYNOPSIS: add new element at beginning of list
Adds the node ’new’ at the beginning of the list. */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
/* 
int	main(void)
{
	int		a = 10;
	int		b = 15;
	int		c = 20;
	t_list *lista = NULL;

	t_list	*a_node = ft_lstnew(&a);
	t_list	*b_node = ft_lstnew(&b);
	t_list	*c_node = ft_lstnew(&c);


	ft_lstadd_front(&lista, a_node);
	ft_lstadd_front(&lista, b_node);
	ft_lstadd_front(&lista, c_node);

	t_list *current = lista;
	while (current)
	{
		printf("Conteúdo do node: ");
		if (current->content)
		{
			printf("%d (int)\n", *((int *)(current->content)));
		}
		current = current->next;
	}

	free(a_node);
	free(b_node);
	free(c_node);
	return (0);
}
 */