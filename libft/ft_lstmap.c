/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:05:41 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/30 12:04:23 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
#include <stdio.h>

void    ft_test(void *content)
{
    char	*str;

	str = content;   
    str[0] = 'X'; 
}

int main(void)
{

    t_list *node_a = ft_lstnew(ft_strdup("um"));
    t_list *node_b = ft_lstnew(ft_strdup("dois"));
    t_list *node_c = ft_lstnew(ft_strdup("tres"));
	t_list	*new_list;
    t_list *current = node_a;
    node_a->next = node_b;
    node_b->next = node_c;

    printf("Conteúdo antes da ft_lstmap:\n");
    while (current)
    {
        printf("%s\n", (char *)(current->content));
        current = current->next;
    }
	new_list = ft_lstmap(node_a, (void *)ft_test, &free);

    current = new_list;
    printf("Conteúdo depois da ft_lstmap:\n");
    while (current)
    {
        printf("%s\n", (char *)(current->content));
        current = current->next;
    }

    //ft_lstclear(&node_a, free);
    ft_lstclear(&new_list, free);
	
    return (0);
}*/