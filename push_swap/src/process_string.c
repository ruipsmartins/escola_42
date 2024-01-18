/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:50:32 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/18 13:46:19 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	process_and_add_to_stack(t_stack **stack_a, char *input)
{
	char	**splited;
	int		i;

	splited = ft_split(input, ' ');
	check_duplicates(splited, input);
	i = 0;
	while (splited[i])
	{
		if (ft_atol(splited[i]) > INT_MAX || ft_atol(splited[i]) < INT_MIN)
			free_and_clear(stack_a, splited, input, i);
		ft_add_stack(stack_a, ft_atol(splited[i]));
		free(splited[i++]);
	}
	free(splited);
}

void	concatenate_and_process_args(t_stack **stack_a, int argc, char **argv)
{
	char	*concatenated_str;
	char	*temp_str;
	int		i;

	if(!argv[1])
		ft_print_error();
	i = 1;
	while (i < argc)
		ft_find_errors(argv[i++]);
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
