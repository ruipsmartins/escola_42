/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:07:12 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/30 14:03:16 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void concatenate_and_process_args(t_stack **stack_a, int argc, char **argv)
{
    int i = 2;
    char *concatenated_str = ft_strjoin(argv[1], " ");

    while (i < argc)
    {
        char *temp_str = ft_strjoin(concatenated_str, argv[i++]);
        free(concatenated_str);
        concatenated_str = ft_strjoin(temp_str, " ");
        free(temp_str);
    }

    // Processar a string resultante e adicionar ao stack_a
    process_and_add_to_stack(stack_a, concatenated_str);

    // Liberar a memória alocada por ft_strjoin
    free(concatenated_str);
} */

int	main(int argc, char **argv)
{
	char	*concatenated_str;
	int		i;
	t_stack	*stack_a;
	t_stack	*tmp;
	char	*temp_str;
	//t_stack	*stack_b;

	stack_a = NULL;
	//ver os erros---------------------
	if (argc < 2 || !argv[1][0])
		ft_print_error();
	// se o argc for igual a 2;
	if(argc == 2)
		process_and_add_to_stack(&stack_a, argv[1]);
	if (argc > 2)
	{
		i = 2;
		concatenated_str = ft_strjoin(argv[1], " ");
		while (i < argc)
		{
			temp_str = ft_strjoin(concatenated_str, argv[i++]);
			free(concatenated_str);
			concatenated_str = ft_strjoin(temp_str, " ");
			free(temp_str);
		}
			process_and_add_to_stack(&stack_a, concatenated_str);
		free(concatenated_str);
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
