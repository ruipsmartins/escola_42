/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filo_routines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:52:19 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/06/25 10:12:18 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
	ft_usleep(1, &philo->table->dead_flag, &philo->table->dead_lock);

}

void	rest(t_table *table, t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	ft_usleep(table->time_to_sleep, &table->dead_flag, &table->dead_lock);
}

void	eat(t_table *table, t_philo *philo)
{
	safe_mutex(&philo->first_fork->fork_mutex, MUTEX_LOCK);
	print_message("has taken a fork", philo, philo->id);
	if (table->num_of_philos == 1)
	{
		ft_usleep(table->time_to_die, &table->dead_flag, &table->dead_lock);
		safe_mutex(&philo->first_fork->fork_mutex, MUTEX_UNLOCK);
		return ;
	}
	safe_mutex(&philo->second_fork->fork_mutex, MUTEX_LOCK);
	print_message("has taken a fork", philo, philo->id);
	philo->eating = 1;
	print_message("is eating", philo, philo->id);
	safe_mutex(&table->meal_lock, MUTEX_LOCK);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	safe_mutex(&table->meal_lock, MUTEX_UNLOCK);
	ft_usleep(table->time_to_eat, &table->dead_flag, &table->dead_lock);
	philo->eating = 0;
	safe_mutex(&philo->first_fork->fork_mutex, MUTEX_UNLOCK);
	safe_mutex(&philo->second_fork->fork_mutex, MUTEX_UNLOCK);
}
