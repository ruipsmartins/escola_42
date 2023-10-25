/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:00:19 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/25 12:51:02 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Iterates the list ’lst’ and applies the function
’f’ on the content of each node.*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*void    ft_test(void *content)
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

    node_a->next = node_b;
    node_b->next = node_c;

    printf("Conteúdo antes da ft_lstlstiter:\n");
    t_list *current = node_a;
    while (current)
    {
        printf("%s\n", (char *)(current->content));
        current = current->next;
    }
	ft_lstiter(node_a, &ft_test);
    current = node_a;
    printf("Conteúdo depois da ft_lstlstiter:\n");
    while (current)
    {
        printf("%s\n", (char *)(current->content));
        current = current->next;
    }

    ft_lstclear(&node_a, free);
	
    return (0);
}*/