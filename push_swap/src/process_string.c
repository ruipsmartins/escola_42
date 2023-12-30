/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:50:32 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/30 14:13:21 by ruidos-s         ###   ########.fr       */
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
	while (splited_input[i])
	{
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
