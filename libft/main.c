/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:05:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/24 16:37:03 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

void ft_del(void *node)
{
    t_list *new_node = (t_list *)node;
    new_node->content = NULL;
}

int    main(void)
{
    int        a = 100;
    int        b = 200;
    int        c = 300;
    t_list *lista = NULL;

    t_list    *a_node = ft_lstnew(&a);
    t_list    *b_node = ft_lstnew(&b);
    t_list    *c_node = ft_lstnew(&c);

    ft_lstadd_front(&lista, c_node);
    ft_lstadd_front(&lista, b_node);
    ft_lstadd_front(&lista, a_node);

    t_list *current = lista;
    while (current)
    {
        if (current->content)
        {
            printf("Conteúdo do node: %d\n", *((int *)(current->content)));
        }
        current = current->next;
    }
    printf("depois de apagar:\n");
    ft_lstdelone(c_node, &ft_del);
    b_node->next = NULL;
    lista = a_node;
    current = lista;
    while (current)
    {
        if (current->content)
        {
            printf("Conteúdo do node: %d\n", *((int *)(current->content)));
        }
        current = current->next;
    }

    free(a_node);
    free(b_node);
    //free(c_node);
    return (0);
}

