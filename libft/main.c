/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:05:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/23 16:14:26 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

int	main(void)
{
	int		a = 10;
	int		b = 15;
	int		c = 20;
	t_list *lista = NULL;

	t_list	*a_node = ft_lstnew(&a);
	t_list	*b_node = ft_lstnew(&b);
	t_list	*c_node = ft_lstnew(&c);


	ft_lstadd_front(&lista, a_node);
	ft_lstadd_front(&lista, b_node);
	ft_lstadd_front(&lista, c_node);

	printf("lst size: %d\n",ft_lstsize(lista));

	t_list *current = lista;
	while (current)
	{
		printf("Conteúdo do node: ");
		if (current->content)
		{
			printf("%d (int)\n", *((int *)(current->content)));
		}
		else
		{
			printf("Nulo\n");
		}

		// Move para o próximo node
		current = current->next;
	}

	free(a_node);
	free(b_node);
	free(c_node);
	return (0);
}

