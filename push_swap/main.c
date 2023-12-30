/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:07:12 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/30 10:52:04 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*tmp;
	//t_stack	*stack_b;

	stack_a = NULL;
	//ver os erros---------------------
	if (argc < 2 || !argv[1][0])
		ft_print_error();
	// se o argc for igual a 2;
	if(argc == 2)
		process_and_add_to_stack(&stack_a, argv[1]);

	//fazer print do que esta no stack a
	while (stack_a)
	{
		printf("Conteúdo do node: ");
		tmp =  stack_a;
		stack_a = tmp->next;
		if (tmp->content)
			printf("%li\n", tmp->content);
		free(tmp);
	}
	free(stack_a);
	return (0);
}
