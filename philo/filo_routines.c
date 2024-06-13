/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filo_routines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:52:19 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/06/13 09:45:05 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
}

void	rest(t_table *table, t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	ft_usleep(table->time_to_sleep, &table->dead_flag, &table->dead_lock);
}

void	eat(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&philo->first_fork->fork_mutex);
	print_message("has taken a fork", philo, philo->id);
	if (table->num_of_philos == 1)
	{
		ft_usleep(table->time_to_die,&table->dead_flag, &table->dead_lock);
		pthread_mutex_unlock(&philo->first_fork->fork_mutex);
		return ;
	}
	pthread_mutex_lock(&philo->second_fork->fork_mutex);
	print_message("has taken a fork", philo, philo->id);
	philo->eating = 1;
	print_message("is eating", philo, philo->id);
	pthread_mutex_lock(&table->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->meal_lock);
	ft_usleep(table->time_to_eat, &table->dead_flag, &table->dead_lock);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->first_fork->fork_mutex);
	pthread_mutex_unlock(&philo->second_fork->fork_mutex);
}
