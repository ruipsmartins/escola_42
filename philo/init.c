/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:08:55 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/31 17:37:51 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_philo *philos, t_table *table,
			t_fork *forks, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		philos[i].table = table;
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
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
		printf("philo nbr = %d, first fork:%d, second fork_%d\n", philos[i].table->philos[i].id, philos[i].first_fork->fork_id, philos[i].second_fork->fork_id);
		i++;
	}
}
void	init_forks(t_fork *forks, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		forks[i].fork_id = i;
		safe_mutex(&forks[i].fork_thread, MUTEX_INIT);
		i++;
	}
}

void	init_table(t_table *table, t_philo *philos, t_fork *forks, char **av)
{
	table->dead_flag = 0;
	table->philos = philos;
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->num_of_philos = ft_atoi(av[1]); 
	table->forks=forks;
	if (av[5])
		table->num_times_to_eat = ft_atoi(av[5]);
	else
		table->num_times_to_eat = -1;

	safe_mutex(&table->write_lock, MUTEX_INIT);
	safe_mutex(&table->dead_lock, MUTEX_INIT);
	safe_mutex(&table->meal_lock, MUTEX_INIT);
}

void	data_init(t_table *table, t_philo *philos, t_fork *forks, char **av)
{

	init_table(table, philos, forks, av);
	init_forks(forks, table->num_of_philos);
	init_philos(philos, table, forks, table->num_of_philos);
}
