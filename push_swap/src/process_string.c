/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:50:32 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/30 10:59:48 by ruidos-s         ###   ########.fr       */
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
