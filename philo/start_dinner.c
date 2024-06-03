/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:25:31 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/06/03 15:29:55 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	dead_loop(t_philo *philo)
{
	t_table *table;
	
	table = philo->table;
	
	pthread_mutex_lock(&table->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(&table->dead_lock), 1);
	pthread_mutex_unlock(&table->dead_lock);
	return (0);
}

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(13);

	while (!dead_loop(philo))
	{
		eat(philo->table, philo);
		think(philo);
		dream(philo->table, philo);
	}
	return (pointer);
}

int	start_dinner(t_table *table)
{
	pthread_t	observer;
	int 		i;

	safe_thread(&observer,&monitor,table->philos, THREAD_CREATE);
	i = 0;
	while (i < table->num_of_philos)
	{
	safe_thread(&table->philos[i].thread, &philo_routine, &table->philos[i], THREAD_CREATE);
	i++;
	}
	i = 0;
	safe_thread(&observer,NULL, NULL, THREAD_JOIN);
	while (i < table->num_of_philos)
	{
		safe_thread(&table->philos[i].thread, NULL, NULL, THREAD_JOIN);
		i++;
	}

	return (0);
}
