/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:25:31 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/29 17:27:45 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thread_create(t_table *table, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int 		i;

	safe_thread(&observer,&monitor,table->philos, THREAD_CREATE);
	



}
