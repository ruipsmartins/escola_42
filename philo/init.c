/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:08:55 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/16 16:12:44 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	data_init(t_table *table)
{
	table->end_simulation = false;
	table->philos = safe_malloc(sizeof(t_philo) * table->nbr_philos);
	table->forks = safe_malloc(sizeof(t_fork) * table->nbr_philos);

}