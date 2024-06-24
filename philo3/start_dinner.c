/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:25:31 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/06/13 14:36:45 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_loop(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	safe_mutex(&table->dead_lock, MUTEX_LOCK);
	if (*philo->dead == 1)
		return (safe_mutex(&table->dead_lock, MUTEX_UNLOCK), true);
	safe_mutex(&table->dead_lock, MUTEX_UNLOCK);
	return (false);
}

void	*philo_routine(void *pointer)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)pointer;
	table = philo->table;
	if (philo->id % 2 == 0)
	{
		think(philo);
		ft_usleep(13, &table->dead_flag, &table->dead_lock);
	}
	while (!dead_loop(philo))
	{
		eat(philo->table, philo);
		rest(philo->table, philo);
		think(philo);
	}
	return (pointer);
}

int	start_dinner(t_table *table)
{
	pthread_t	observer;
	int			i;

	safe_thread(&observer, &monitor, table->philos, THREAD_CREATE);
	i = 0;
	while (i < table->num_of_philos)
	{
		safe_thread(&table->philos[i].thread,
			&philo_routine, &table->philos[i], THREAD_CREATE);
		i++;
	}
	i = 0;
	safe_thread(&observer, NULL, NULL, THREAD_JOIN);
	while (i < table->num_of_philos)
	{
		safe_thread(&table->philos[i].thread, NULL, NULL, THREAD_JOIN);
		i++;
	}
	return (0);
}
