/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:27:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/24 14:56:40 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Takes as a parameter a node and frees the memory of
the node’s content using the function ’del’ given
as a parameter and free the node. The memory of
’next’ must not be freed. */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

/* void ft_del(void *node)
{
    t_list *new_node = (t_list *)node;
    new_node->content = NULL;
}

int	main(void)
{
	int		a = 100;
	int		b = 200;
	int		c = 300;
	t_list *lista = NULL;

	t_list	*a_node = ft_lstnew(&a);
	t_list	*b_node = ft_lstnew(&b);
	t_list	*c_node = ft_lstnew(&c);

	ft_lstdelone(c_node, &ft_del);

	//ft_lstadd_front(&lista, c_node);
	ft_lstadd_back(&lista, b_node);
	ft_lstadd_front(&lista, a_node);


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
	//free(c_node);
	return (0);
}
 */