/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:25:28 by bruno             #+#    #+#             */
/*   Updated: 2024/04/01 23:56:14 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	t_list	*temp;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		temp = ((*f)(lst->content));
		new = ft_lstnew(temp);
		if (!new)
		{
			(*del)(temp);
			ft_lstclear(&first, (del));
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
