/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:08:55 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/20 14:50:59 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_philo *philo, t_fork *forks, int philo_position)
{
	int	nbr_philos;

	nbr_philos = philo->table->nbr_philos;
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position + 1) % nbr_philos];
	}
	else
	{
		philo->second_fork = &forks[philo_position];
		philo->first_fork = &forks[(philo_position + 1) % nbr_philos];
	}
}

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < table->nbr_philos)
	{
		philo = &table->philos[i];
		philo->id = i + 1;
		philo->meals_counter = 0;
		philo->full = false;
		philo->table = table;
		assign_forks(philo, table->forks, i);
		i++;
	}
}

void	data_init(t_table *table)
{
	int	i;

	i = 0;
	table->end_simulation = false;
	table->philos = safe_malloc(sizeof(t_philo) * table->nbr_philos);
	table->forks = safe_malloc(sizeof(t_fork) * table->nbr_philos);
	while (i < table->nbr_philos)
	{
		mutex_handle(&table->forks[i].fork, MUTEX_INIT);
		table->forks[i].fork_id = i; //for debug
		i++;
	}
	philo_init(table);
}
