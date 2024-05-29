/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:30:36 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/29 18:08:29 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
 ./philo 5 800 200 200 6 
5 — The number of philosophers
800 — The time a philosopher will die if he doesn’t eat
200 — The time it takes a philosopher to eat
200 — The time it takes a philosopher to sleep
6 — Number of times all the philosophers need to eat before terminating the program **
*/

int	main(int ac, char **av)
{
	t_table			table;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	if (ac != 5 && ac != 6)
		print_error("Wrong number of arguments.");
	//1) errors checking
	check_arguments(av);
	philos = (t_philo *)safe_malloc(ft_atoi(av[1]) * sizeof(t_philo));
	forks = (pthread_mutex_t *)safe_malloc(ft_atoi(av[1])* sizeof(pthread_mutex_t));
	//2) init stuff
	data_init(&table, philos, forks, av);

	//3) start dinner
	
	//4) clean table
	clean_table(NULL, &table, forks);

	return (0);
}
