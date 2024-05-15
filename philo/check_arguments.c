/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:01:52 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/15 17:36:51 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *str)
{
	long	number;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	number = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number * sign);
}

void	check_errors(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atol(av[i++]) < 1)
		{
			printf("there is an error in the arguments\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	check_arguments(t_table table, char **av)
{
	int	i;

	i = 0;
	i++;
	check_errors(av);
	table.nbr_philos = ft_atol(av[1]);
	table.time_to_die = ft_atol(av[2]) * 1000;
	table.time_to_eat = ft_atol(av[3]) * 1000;
	table.time_to_sleep = ft_atol(av[4]) * 1000;
	if (av[5])
		table.nbr_of_meals = ft_atol(av[5]);
	else
		table.nbr_of_meals = -1;
	printf("number of philos %ld\n", table.nbr_philos);
	printf("time to die %ld\n", table.time_to_die);
	printf("time to eat %ld\n", table.time_to_eat);
	printf("time to sleep %ld\n", table.time_to_sleep);
	printf("number of meals %ld\n", table.nbr_of_meals);
}
