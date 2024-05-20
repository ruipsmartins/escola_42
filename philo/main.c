/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:30:36 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/20 17:26:36 by ruidos-s         ###   ########.fr       */
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

void *print_message(void *message) {
    printf("%s\n", (char *)message);
    return NULL;
}
// ./philo 5 800 200 200 5

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		//1) errors checking
		check_arguments(&table, av);

		//2) init data and philos
		data_init(&table);
		print_philos(&table);
		
		//3)
		pthread_t thread;
    	char *message = "Hello, Threads!";
    	// Criar a thread
    	thread_handle(&thread, print_message, (void *)message, THREAD_CREATE);

    	// Esperar a thread terminar
    	thread_handle(&thread, NULL, NULL, THREAD_JOIN);
		//start_eating(&table);

		//4) No leaks -> philos full || 1 philo died
		clean_table(&table);
   
	}
	else
	{
		print_error("Wrong number of arguments.");
	}

	return (0);
}
