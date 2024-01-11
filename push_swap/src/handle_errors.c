/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:02:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/11 14:34:35 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_print_error(void)
{
	write(1, "Error\n", 7);
	exit(1);
}

void	ft_find_errors(char *str)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			num = 1;
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' 
			&& str[i] != '-' && str[i] != '+')
			ft_print_error();
		if ((str[i] == '-' || str[i] == '+') && (str[i + 1] < '0'
				|| str[i + 1] > '9'))
			ft_print_error();
		i++;
	}
	//aqui ver se é para dar erro ou exit.
	if (num == 0)
		exit(1);
}

void	ft_clear_stack(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	while (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
}

void	free_and_clear(t_stack **stack_a, char **splited, char *input, int i)
{
	ft_clear_stack(stack_a);
	while (splited[i])
		free(splited[i++]);
	free(splited);
	free(input);
	ft_print_error();
}

void	check_duplicates(char **splited, char *input)
{
	int		i;
	int		l;

	i = 0;
	l = 1;
	while (splited[i])
	{
		while (splited[l])
		{
			if (ft_atol(splited[i]) == ft_atol(splited[l]))
			{
				i = 0;
				while (splited[i])
					free(splited[i++]);
				free(splited);
				free(input);
				ft_print_error();
			}
			l++;
		}
		l = i + 2;
		i++;
	}
}
