/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:30:36 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/16 17:01:38 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_test(int mutex_action)
{
	if (mutex_action == MUTEX_INIT)
	{
		printf("INIT\n");
	}
	else if (mutex_action == MUTEX_DESTROY)
	{
		printf("mutex destroy\n");
	}
}
// ./philo 5 800 200 200 5
int	main(int ac, char **av)
{
	t_table	table;

	ft_test(MUTEX_DESTROY);
	ft_test(MUTEX_INIT);
	if (ac == 5 || ac == 6)
	{
		//1) errors cheacking, filling table
		check_arguments(&table, av);
		printf("number of philos %ld\n", table.nbr_philos);
		printf("time to die %ld\n", table.time_to_die);
		printf("time to eat %ld\n", table.time_to_eat);
		printf("time to sleep %ld\n", table.time_to_sleep);
		printf("number of meals %ld\n", table.nbr_of_meals);

		//2) creating actual thing
		//data_init(&table);

		//3)
		//dinner_start(&table);

		//4) No leaks -> philos full || 1 philo died
		//clean(&table);
	}
	else
	{
		print_error("Wrong number of arguments.");
	}

	return (0);
}
