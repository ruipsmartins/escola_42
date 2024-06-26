/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:01:52 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/06/19 12:21:11 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg_content(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	check_arguments(char **av)
{
	if (av[5] && av[5][0] == '0')
		exit(EXIT_SUCCESS);
	if (ft_atol(av[1]) > 200 || ft_atol(av[1]) <= 0
		|| check_arg_content(av[1]) == 1)
		print_error("Invalid philosophers number\n", true);
	if (ft_atol(av[2]) > INT_MAX || ft_atol(av[2]) <= 0
		|| check_arg_content(av[2]) == 1)
		print_error("Invalid time to die\n", true);
	if (ft_atol(av[3]) > INT_MAX || ft_atol(av[3]) <= 0
		|| check_arg_content(av[3]) == 1)
		print_error("Invalid time to eat\n", true);
	if (ft_atol(av[4]) > INT_MAX || ft_atol(av[4]) <= 0
		|| check_arg_content(av[4]) == 1)
		print_error("Invalid time to sleep\n", true);
	if (av[5] && (ft_atol(av[5]) > INT_MAX || ft_atol(av[5]) < 0
			|| check_arg_content(av[5]) == 1))
		print_error("Invalid number of meals\n", true);
}
