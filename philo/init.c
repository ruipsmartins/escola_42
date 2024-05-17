/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:08:55 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/17 12:10:12 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	int i = 0;
	while (i < table->nbr_philos)
	{
		philo = &table->philos[i];
		philo->id = i + 1;
		philo->meals_counter = 0;
		philo->full = false;
		philo->table = table;
		
		
		i++;
	}
	

}

void	data_init(t_table *table)
{
	int	i;

	int i = 0;
	table->end_simulation = false;
	table->philos = safe_malloc(sizeof(t_philo) * table->nbr_philos);
	table->forks = safe_malloc(sizeof(t_fork) * table->nbr_philos);
	while(i < table->nbr_philos)
	{
		mutex_handle(&table->forks[i].fork, MUTEX_INIT);
		table->forks[i].fork_id = i; //for debug
	}

	//make init for philos 46:30

}
