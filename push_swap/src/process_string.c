/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:50:32 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/30 16:43:27 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	process_and_add_to_stack(t_stack **stack_a, char *input)
{
	char	**splited_input;
	int		i;

	ft_find_errors(input);
	splited_input = ft_split(input, ' ');
	i = 0;
	// nao esta a dar: ./teste "54 65 656554 445 556 33555555555555"
	while (splited_input[i])
	{
		if (ft_atol(splited_input[i]) > INT_MAX || ft_atol(splited_input[i]) < INT_MIN)
		{
			ft_clear_stack(&*stack_a);

			while (splited_input[i])
			{	
				printf("freed splited_input %d\n",i);
				free(splited_input[i++]);
			}
			free(splited_input);
			free(input);
			ft_print_error();
		}
		ft_add_stack(stack_a, ft_atol(splited_input[i]));
		free(splited_input[i++]);
	}
	free(splited_input);
}

void	concatenate_and_process_args(t_stack **stack_a, int argc, char **argv)
{
	int		i;
	char	*concatenated_str;
	char	*temp_str;

	i = 2;
	concatenated_str = ft_strjoin(argv[1], " ");
	while (i < argc)
	{
		temp_str = ft_strjoin(concatenated_str, argv[i++]);
		free(concatenated_str);
		concatenated_str = ft_strjoin(temp_str, " ");
		free(temp_str);
	}
	process_and_add_to_stack(stack_a, concatenated_str);
	free(concatenated_str);
}
