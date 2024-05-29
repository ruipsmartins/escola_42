/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:08:55 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/29 19:19:18 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	init_forks(pthread_mutex_t *forks, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
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
		char **av, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
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
		if (i % 2 == 0)
		{
			philos[i].l_fork = &forks[i];
			philos[i].r_fork = &forks[(i + 1) % num_philos];
		}
		else
		{
		philos[i].r_fork = &forks[i];
		philos[i].l_fork = &forks[(i + 1) % num_philos];
		}
		i++;	
	}
}

void	data_init(t_table *table, t_philo *philos, pthread_mutex_t *forks, char **av)
{
	int num_philos;

	num_philos = ft_atoi(av[1]);
	init_table(table, philos);
	init_forks(forks, num_philos);
	init_philos(philos, table, forks, av, num_philos);
}
