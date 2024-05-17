/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:55:41 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/17 11:42:10 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		print_error("Error using malloc");
	return (ptr);
}

void	mutex_handle(pthread_mutex_t *mutex, int mutex_action)
{
	if (mutex_action == MUTEX_INIT)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			print_error("Error INIT mutex");
	}
	else if (mutex_action == MUTEX_LOCK)
	{
		if (pthread_mutex_lock(mutex) != 0)
			print_error("Error locking mutex");
	}
	else if (mutex_action == MUTEX_UNLOCK)
	{
		if (pthread_mutex_unlock(mutex) != 0)
			print_error("Error unlocking mutex");
	}
	else if (mutex_action == MUTEX_DESTROY)
	{
		if (pthread_mutex_destroy(mutex) != 0)
			print_error("Error destroying mutex");
	}
	else
		print_error("Wrong mutex_action");
}
