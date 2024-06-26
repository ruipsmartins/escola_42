/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:30:36 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/06/13 15:32:48 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
 ./philo 5 800 200 200 6 
5 — The number of philosophers
800 — The time a philosopher will die if he doesn’t eat
200 — The time it takes a philosopher to eat
200 — The time it takes a philosopher to sleep
6 — Number of times all the philosophers need to eat**
*/

int	main(int ac, char **av)
{
	static t_table			table;
	static t_philo			philos[200];
	static t_fork			forks[200];

	if (ac != 5 && ac != 6)
		print_error("Wrong number of arguments.", true);
	check_arguments(av);
	data_init(&table, philos, forks, av);
	start_dinner(&table);
	clean_table(NULL, &table, true);
	return (0);
}
