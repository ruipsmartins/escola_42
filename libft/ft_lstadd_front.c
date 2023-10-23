/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:53:51 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/23 12:28:51 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* SYNOPSIS: add new element at beginning of list
Adds the node ’new’ at the beginning of the list. */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
