/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:49:38 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/30 12:04:26 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’. The variable
’next’ is initialized to NULL. */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/* 
#include <stdio.h>

int	main(void)
{
	int		int_data;
	float	float_data;
	char	char_data;

	int_data = 10;
	float_data = 15.7;
	char_data = 'Z';

	t_list	*int_node = ft_lstnew(&int_data);
	t_list	*float_node = ft_lstnew(&float_data);
	t_list	*char_node = ft_lstnew(&char_data);

	int_node->next = float_node;
	float_node->next = char_node;

	printf("conteudo do int_node: %d\n", *(int *)int_node->content);
	printf("conteudo do float_node: %f\n", *(float *)float_node->content);
	printf("conteudo do char_node: %c\n", *(char *)char_node->content);

	printf("conteudo do char_node atravez do 
	float_node %c\n",*(char *)float_node->next->content);

	free(int_node);
	free(float_node);
	free(char_node);
	return (0);
}
 */