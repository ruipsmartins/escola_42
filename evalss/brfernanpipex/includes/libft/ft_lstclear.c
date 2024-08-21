/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:25:19 by bruno             #+#    #+#             */
/*   Updated: 2024/04/01 23:56:01 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	while (lst && *lst)
	{
		temp = (*lst)->next;
		if (del)
			del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
