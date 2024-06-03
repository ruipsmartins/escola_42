/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:01:57 by druina            #+#    #+#             */
/*   Updated: 2024/06/03 15:05:01 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Checks if the value of dead_flag changed

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

// Thread routine

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(13);

	while (!dead_loop(philo))
	{
		eat(philo);
		think(philo);
		dream(philo);
	}
	return (pointer);
}

// Creates all the threads

int	start_dinner(t_table *table, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, table->philos) != 0)
		destory_all("Thread creation error", table, forks);
	i = 0;
	while (i < table->philos[0].num_of_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &philo_routine,
				&table->philos[i]) != 0)
			destory_all("Thread creation error", table, forks);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		destory_all("Thread join error", table, forks);
	while (i < table->philos[0].num_of_philos)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
			destory_all("Thread join error", table, forks);
		i++;
	}
	return (0);
}
