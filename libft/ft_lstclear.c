/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:40:21 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/24 19:24:33 by ruidos-s         ###   ########.fr       */
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
//FAZER TESTES!!!!!!!!!!!!!