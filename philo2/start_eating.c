/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:32:06 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/27 15:58:58 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_routine(void *data)
{
	t_philo *philo;
	philo = (t_philo *)data;
	philo++;
	return(NULL);
}


void	start_eating(t_table *table)
{
	int	i;

	i = 0;

	while (i < table->nbr_philos)
	{
		safe_thread(&table->philos[i].thread_id, start_routine,
					&table->philos[i], THREAD_CREATE);
		i++;
	}
	

}