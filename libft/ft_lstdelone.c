/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:27:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/30 12:04:54 by ruidos-s         ###   ########.fr       */
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

    ft_lstdelone(node_b, &ft_del);
	//node_a->next = node_c;
    printf("Conteúdo depois da ft_lstdelone:\n");
    current = node_a;
    while (current)
    {
        printf("%s\n", (char *)(current->content));
        current = current->next;
    }

    // Liberando a memória dos nós restantes
    free(node_a);
    free(node_c);

    return (0);
}
*/