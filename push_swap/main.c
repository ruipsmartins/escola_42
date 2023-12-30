/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:07:12 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/30 10:40:14 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void process_and_add_to_stack(t_stack **stack_a, const char *input)
{
	char	**splited_input;
	int		i;

	ft_find_errors(input);

	i = 0;
	i++;
}*/


int	main(int argc, char **argv)
{
	int		i;
	char	**splited_argv;
	t_stack	*stack_a;
	t_stack	*tmp;
	//t_stack	*stack_b;

	stack_a = NULL;
	//ver os erros---------------------
	if (argc < 2 || !argv[1][0])
		ft_print_error();
	// se o argc for igual a 2;
	if(argc == 2)
	{
		ft_find_errors(argv[1]);
		splited_argv = ft_split(argv[1], ' ');
		i = 0;
		//adicionar tudo ao stack_a
		while (splited_argv[i])
		{
			ft_add_stack(&stack_a, ft_atol(splited_argv[i]));
			free(splited_argv[i++]);
		}
		free(splited_argv);
	}

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
