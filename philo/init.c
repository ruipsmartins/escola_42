/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:08:55 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/27 19:06:12 by ruidos-s         ###   ########.fr       */
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
void	init_input(t_philo *philo, char **av)
{
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->num_of_philos = ft_atoi(av[1]);
	if (av[5])
		philo->num_times_to_eat = ft_atoi(av[5]);
	else
		philo->num_times_to_eat = -1;
}

void	init_philos(t_philo *philos, t_table *table, pthread_mutex_t *forks,
		char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		init_input(&philos[i], av);
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].write_lock = &table->write_lock;
		philos[i].dead_lock = &table->dead_lock;
		philos[i].meal_lock = &table->meal_lock;
		philos[i].dead = &table->dead_flag;
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;	
	}
}

void	data_init(t_table *table, t_philo *philos, pthread_mutex_t *forks, char **av)
{
	init_table(table, philos);
	init_forks(forks, ft_atoi(av[1]));
	init_philos(philos, table, forks, av);
}
