/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:07:12 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/21 18:13:47 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*tmp;
	//t_stack	*stack_b;
	//ver os erros---------------------
	if (argc < 2 || !argv[1][0])
		ft_print_error();
	ft_find_errors(argv[1]);
	argv = ft_split(argv[1], ' ');
	stack_a = NULL;
	i = 0;
	//adicionar tudo ao stack_a
	while (argv[i])
		ft_add_stack(&stack_a, ft_atol(argv[i++]));
	//fazer print do que esta no stack a
	while (stack_a)
	{
		printf("Conteúdo do node: ");
		if (stack_a->content)
		{	
			tmp =  stack_a;
			printf("%li\n", tmp->content);
			free(stack_a);
		}
		stack_a = tmp->next;
	}
	return (0);
}
