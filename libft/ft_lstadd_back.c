/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:23:04 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/24 11:57:57 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Adds the node ’new’ at the end of the list. */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}
/* int	main(void)
{
	int		a = 10;
	int		b = 15;
	int		c = 20;
	t_list *lista = NULL;

	t_list	*a_node = ft_lstnew(&a);
	t_list	*b_node = ft_lstnew(&b);
	t_list	*c_node = ft_lstnew(&c);

	ft_lstadd_front(&lista, c_node);
	ft_lstadd_front(&lista, a_node);
	ft_lstadd_back(NULL, b_node);


	t_list *current = lista;
	while (current)
	{
		printf("Conteúdo do node: ");
		if (current->content)
		{
			printf("%d\n", *((int *)(current->content)));
		}
		// Move para o próximo node
		current = current->next;
	}
	t_list *last = (void *)ft_lstlast(lista);
	printf("ultimo da lista: %d\n", *((int *)(last->content)));

	free(a_node);
	free(b_node);
	free(c_node);
	return (0);
}

 */