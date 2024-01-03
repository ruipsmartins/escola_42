/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:07:12 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/03 17:23:39 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*tmp;
	//t_stack	*stack_b;

	stack_a = NULL;
	// Perguntar ao pessoal se é para fazer print ao erro ou nao se nao tiver args
	/*if (argc < 2 || !argv[1][0])
		ft_print_error();*/
	if (argc >= 2)
		concatenate_and_process_args(&stack_a, argc, argv);
	//fazer print do que esta no stack a
	tmp =  stack_a;
	while (tmp)
	{
		printf("Conteúdo do node: ");
		if (tmp->content)
			{
				printf("%li\n", tmp->content);
				if (tmp->prev)
					printf("prev: %li\n", tmp->prev->content);
				else
					printf("prev = NULL\n");
				if(tmp->next)
					printf("next: %li\n", tmp->next->content);
				else
					printf("next: NULL\n");
				printf("----------------------------\n");
			}
			tmp = tmp->next;
	}

	while(stack_a->next)
	{
		stack_a = stack_a->next;
		free(stack_a->prev); 
	}
	free(stack_a);
	return (0);
}
