/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:27:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/25 11:07:39 by ruidos-s         ###   ########.fr       */
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
void    ft_del(void *content)
{
    content = NULL;
}

int main(void)
{
    int a = 10;
    int b = 20;
    int c = 30;

    t_list *node_a = ft_lstnew(&a);
    t_list *node_b = ft_lstnew(&b);
    t_list *node_c = ft_lstnew(&c);

    // Criando a lista encadeada
    node_a->next = node_b;
    node_b->next = node_c;

    printf("Conteúdo antes da deleção:\n");
    t_list *current = node_a;
    while (current)
    {
        printf("%d\n", *((int *)(current->content)));
        current = current->next;
    }

    // Deletando um nó específico da lista
    ft_lstdelone(node_b, &ft_del);
	node_a->next = node_c;
    printf("Conteúdo depois da deleção:\n");
    //current = node_a;
    while (current)
    {
        printf("%d\n", *((int *)(current->content)));
        current = current->next;
    }

    // Liberando a memória dos nós restantes
    free(node_a);
    free(node_c);

    return (0);
}
*/