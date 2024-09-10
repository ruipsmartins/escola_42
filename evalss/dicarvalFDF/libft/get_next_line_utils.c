/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:59:54 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/26 17:36:09 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_content(t_gnl **lnklist, t_gnl *char_n_used)
{
	t_gnl	*tmp;
	t_gnl	*current;

	if (*lnklist == NULL)
		return ;
	current = *lnklist;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp->buf);
		free(tmp);
	}
	*lnklist = NULL;
	if (char_n_used->buf[0] != '\0')
		*lnklist = char_n_used;
	else
	{
		free(char_n_used->buf);
		free(char_n_used);
	}
}

size_t	list_len(t_gnl *lnklist)
{
	size_t	line_len;
	int		i;

	line_len = 0;
	if (lnklist == NULL)
		return (0);
	while (lnklist != NULL)
	{
		i = 0;
		while (lnklist->buf[i] != '\0')
		{
			if (lnklist->buf[i] == '\n')
			{
				return (++line_len);
			}
			i++;
			line_len++;
		}
		lnklist = lnklist->next;
	}
	return (line_len);
}

int	end_line(t_gnl *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buf[i] != '\0')
		{
			if (list->buf[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

t_gnl	*lstlast(t_gnl *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_gnl **lst, t_gnl *new)
{
	t_gnl	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = lstlast(*lst);
		last->next = new;
	}
}
