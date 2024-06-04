/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:40:00 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/06/04 13:49:23 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Print message funtion

void	print_message(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(&philo->table->write_lock);
	time = get_current_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(&philo->table->write_lock);
}

// Checks if the philosopher is dead

int	philosopher_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(&philo->table->meal_lock);
	if (get_current_time() - philo->last_meal >= time_to_die
		&& philo->eating == 0)
		return (pthread_mutex_unlock(&philo->table->meal_lock), 1);
	pthread_mutex_unlock(&philo->table->meal_lock);
	return (0);
}

// Check if any philo died

int	check_if_dead(t_philo *philos)
{
	int		i;
	t_table	*table;

	table = philos->table;
	i = 0;
	while (i < table->num_of_philos)
	{
		if (philosopher_dead(&philos[i], table->time_to_die))
		{
			print_message("died", &philos[i], philos[i].id);
			pthread_mutex_lock(&table->dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(&table->dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

// Checks if all the philos ate the num_of_meals

int	check_if_all_ate(t_philo *philos)
{
	int		i;
	t_table	*table;
	int		finished_eating;

	table = philos->table;
	i = 0;
	finished_eating = 0;
	if (table->num_times_to_eat == -1)
		return (0);
	while (i < table->num_of_philos)
	{
		pthread_mutex_lock(&table->meal_lock);
		if (philos[i].meals_eaten >= table->num_times_to_eat)
			finished_eating++;
		pthread_mutex_unlock(&table->meal_lock);
		i++;
	}
	if (finished_eating == table->num_of_philos)
	{
		pthread_mutex_lock(&table->dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(&table->dead_lock);
		return (1);
	}
	return (0);
}

// Monitor thread routine

void	*monitor(void *pointer)
{
	t_philo	*philos;

	philos = (t_philo *)pointer;
	while (1)
		if (check_if_dead(philos) == 1 || check_if_all_ate(philos) == 1)
			break ;
	return (pointer);
}
