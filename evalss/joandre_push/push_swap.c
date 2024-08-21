/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 07:40:17 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/09 13:44:16 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	input_check(int argc, char **argv, t_stack **a)
{
	int		i;
	char	**nbr;

	if (argv_check(argc, argv))
	{
		if (argc > 2)
			create_stack(a, argv, 1);
		else if (argc == 2)
		{
			nbr = ft_split(argv[1], ' ');
			create_stack(a, nbr, 0);
			i = 0;
			while (nbr[i])
				free(nbr[i++]);
			free(nbr);
		}
		if (int_repeat(*a) || stack_size(*a) < 3)
		{
			free_stack(*a);
			return (false);
		}
		return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_stack	**a;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	a = malloc(sizeof(t_stack));
	if (a == NULL)
		return (2);
	if (input_check(argc, argv, a))
	{
		sort_algo(a);
		free_stack(*a);
	}
	else
		write(2, "Error\n", 6);
	free(a);
	return (0);
}
