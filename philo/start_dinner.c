/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:25:31 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/31 17:45:31 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	dead_loop(t_philo *philo)
{
	t_table *table = &philo->table;
	
	pthread_mutex_lock(&table->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(&table->dead_lock), 1);
	pthread_mutex_unlock(&table->dead_lock);
	return (0);
}


int	start_dinner(t_table *table, t_fork *forks)
{
	pthread_t	observer;
	int 		i;

	//safe_thread(&monitor,&ft_monitor,table->philos, THREAD_CREATE);
	i = 0;
	while (i < table->num_of_philos)
	{
	safe_thread(&table->philos[i].thread, &philo_routine, &table->philos[i], THREAD_CREATE);
	i++;
	}
	i = 0;
	while (i < table->num_of_philos)
	{
		safe_thread(table->philos[i].thread, NULL, NULL, THREAD_JOIN);
	}
	




}
