/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:05:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/25 11:08:43 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

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

