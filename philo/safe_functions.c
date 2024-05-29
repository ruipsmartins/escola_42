/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:55:41 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/29 17:57:35 by ruidos-s         ###   ########.fr       */
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

void	safe_mutex(pthread_mutex_t *mutex, int e_mutex_action)
{
	if (e_mutex_action == MUTEX_INIT)
	{
		printf("teste mutex init\n");
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
		printf("teste mutex destroy\n");
		if (pthread_mutex_destroy(mutex) != 0)
			print_error("Error destroying mutex");
	}
	else
		print_error("Wrong e_mutex_action");
}

void	safe_thread(pthread_t *thread,
					void *(*start_routine) (void *),
					void *data, int e_thread_action)
{
	if (e_thread_action == THREAD_CREATE)
	{
		if (pthread_create(thread, NULL, start_routine, data) != 0)
			print_error("Error creating thread");
	}
	else if (e_thread_action == THREAD_JOIN)
	{
		if (pthread_join(*thread, NULL) != 0)
			print_error("Error joining thread");
	}
	else if (e_thread_action == THREAD_DETACH)
	{
		if (pthread_detach(*thread) != 0)
			print_error("Error detaching thread");
	}
	else
		print_error("wrong e_thread_action");
}
