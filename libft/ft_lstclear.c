/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:40:21 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/30 12:05:01 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Deletes and frees the given node and every
successor of that node, using the function ’del’
and free(3).
Finally, the pointer to the list must be set to
NULL. */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (!*lst)
		return ;
	while (*lst)
	{
		aux = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(aux, del);
	}
	*lst = NULL;
}
/*
#include <stdio.h>

void    ft_del(void *content)
{
    free(content);
}

int main(void)
{

    t_list *node_a = ft_lstnew(ft_strdup("um"));
    t_list *node_b = ft_lstnew(ft_strdup("dois"));
    t_list *node_c = ft_lstnew(ft_strdup("tres"));

    node_a->next = node_b;
    node_b->next = node_c;

    printf("Conteúdo antes da ft_lstdelone:\n");
    t_list *current = node_a;
    while (current)
    {
        printf("%s\n", (char *)(current->content));
        current = current->next;
    }

    ft_lstclear(&node_b, &ft_del);
	node_a->next = NULL;
    current = node_a;
    printf("Conteúdo depois da ft_lstdelone:\n");
    while (current)
    {
        printf("%s\n", (char *)(current->content));
        current = current->next;
    }

    free(node_a);
	//free(node_b);
    //free(node_c);
    return (0);
}*/