/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:20:10 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/23 19:36:30 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns the last node of the list. */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
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

	ft_lstadd_front(&lista, a_node);
	ft_lstadd_front(&lista, b_node);
	ft_lstadd_front(&lista, c_node);

	t_list *last = (void *)ft_lstlast(lista);
	printf("ultimo da lista: %d\n", *((int *)(last->content)));

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

	free(a_node);
	free(b_node);
	free(c_node);
	return (0);
}
 */