/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:02:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/12/30 16:40:26 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_print_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

void	ft_find_errors(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' 
			&& str[i] != '-' && str[i] != '+')
			ft_print_error();
		if ((str[i] == '-' || str[i] == '+') && (str[i + 1] < '0'
				|| str[i + 1] > '9'))
			ft_print_error();
		i++;
	}
}

void	ft_clear_stack(t_stack **stack_a)
{
	t_stack *tmp;

	while (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
}

void	handle_errors_and_free(t_stack **stack_a, char **splited_input, char *input)
{
	int	i;

	i = 0;
	ft_clear_stack(stack_a);

			while (splited_input[i])
			{	
				printf("freed splited_input %d\n",i);
				free(splited_input[i++]);
			}
			free(splited_input);
			free(input);
			ft_print_error();
}