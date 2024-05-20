/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:30:36 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/20 14:43:50 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_philos(t_table *table) {
    for (int i = 0; i < table->nbr_philos; i++) {
        t_philo *philo = &table->philos[i];
        printf("Philosopher %d: first fork ID = %d, second fork ID = %d\n",
               philo->id,
               philo->first_fork->fork_id,
               philo->second_fork->fork_id);
    }
}
// ./philo 5 800 200 200 5
int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		//1) errors cheacking, filling table
		check_arguments(&table, av);

		//2) creating actual thing
		data_init(&table);
		print_philos(&table);
		
		//3)
		//dinner_start(&table);

		//4) No leaks -> philos full || 1 philo died
		clean_table(&table);
   
	}
	else
	{
		print_error("Wrong number of arguments.");
	}

	return (0);
}
