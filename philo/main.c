/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:30:36 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/15 15:07:41 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ./philo 5 800 200 200 [5]
int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		printf("hello %s!\n", av[0]);
		//1) errors cheacking, filling table
		parse_input(&table, av);

		//2) creating actual thing
		data_init(&table);

		//3)
		dinner_start(&table);

		//4) No leaks -> philos full || 1 philo died
		clean(&table);
		
	}
	else
	{
		printf("wrong args: should be like ./philo 5 800 200 200 [5]");
		exit(EXIT_FAILURE);
	}
	return (0);
}
