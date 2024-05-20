/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:55:41 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/20 14:53:01 by ruidos-s         ###   ########.fr       */
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

void	mutex_handle(pthread_mutex_t *mutex, int e_mutex_action)
{
	if (e_mutex_action == MUTEX_INIT)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			print_error("Error INIT mutex");
	}
	else if (e_mutex_action == MUTEX_LOCK)
	{
		if (pthread_mutex_lock(mutex) != 0)
			print_error("Error locking mutex");
	}
	else if (e_mutex_action == MUTEX_UNLOCK)
	{
		if (pthread_mutex_unlock(mutex) != 0)
			print_error("Error unlocking mutex");
	}
	else if (e_mutex_action == MUTEX_DESTROY)
	{
		if (pthread_mutex_destroy(mutex) != 0)
			print_error("Error destroying mutex");
	}
	else
		print_error("Wrong e_mutex_action");
}
