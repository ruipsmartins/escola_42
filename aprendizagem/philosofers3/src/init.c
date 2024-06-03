/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:05:40 by druina            #+#    #+#             */
/*   Updated: 2024/06/03 15:05:01 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Initializing the input from user

void	init_input(t_philo *philo, char **argv)
{
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->num_of_philos = ft_atoi(argv[1]);
	if (argv[5])
		philo->num_times_to_eat = ft_atoi(argv[5]);
	else
		philo->num_times_to_eat = -1;
}

// Initializing the philosophers

void	init_philos(t_philo *philos, t_table *table, pthread_mutex_t *forks,
		char **argv)
{
	int	i;
	int num_philos = ft_atoi(argv[1]);
	i = 0;
	while (i < num_philos)
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		init_input(&philos[i], argv);
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].write_lock = &table->write_lock;
		philos[i].dead_lock = &table->dead_lock;
		philos[i].meal_lock = &table->meal_lock;
		philos[i].dead = &table->dead_flag;

		if (i % 2 == 0)
		{
			philos[i].second_fork = &forks[i + 1];
			philos[i].first_fork = &forks[(i) % num_philos];
		}
		else
		{
			philos[i].first_fork = &forks[i + 1];
			philos[i].second_fork = &forks[(i) % num_philos];
		}
		
		/* philos[i].second_fork = &forks[i];
		if (i == 0)
			philos[i].first_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].first_fork = &forks[i - 1];*/
		
		i++;
	}
}

// Initializing the forks mutexes

void	init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

// Initializing the program structure

void	init_program(t_table *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->philos = philos;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}
