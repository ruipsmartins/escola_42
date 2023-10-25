/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:05:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/25 16:56:04 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

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
	/////////////
    ft_lstclear(&node_b, free);
	node_a->next = NULL;
    current = node_a;
    printf("Conteúdo depois da ft_lstdelone:\n");
    while (current)
    {
        printf("%s\n", (char *)(current->content));
        current = current->next;
    }

    free(node_a);
	free(node_b);
    //free(node_c);
    return (0);
}

