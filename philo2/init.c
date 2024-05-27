/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:08:55 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/27 17:50:25 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		//pthread_mutex_init(&forks[i], NULL);
		safe_mutex(&forks[i], MUTEX_INIT);
		i++;
	}
}
void	init_table(t_table *table, t_philo *philos)
{
	table->dead_flag = 0;
	table->philos = philos;
	safe_mutex(&table->write_lock, MUTEX_INIT);
	safe_mutex(&table->dead_lock, MUTEX_INIT);
	safe_mutex(&table->meal_lock, MUTEX_INIT);

/* 	pthread_mutex_init(&table->write_lock, NULL);
	pthread_mutex_init(&table->dead_lock, NULL);
	pthread_mutex_init(&table->meal_lock, NULL); */
}

void	data_init(t_table *table, t_philo *philos, pthread_mutex_t *forks, char **av)
{
	init_table(table, philos);
	init_forks(forks, ft_atoi(av[1]));
	
}
