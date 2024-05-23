/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:30:31 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/23 14:33:50 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_table	t_table;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}					t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_table		*table;
}				t_philo;

typedef struct s_table
{
	long		nbr_philos;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nbr_of_meals;
	long		start_simulation;
	bool		end_simulation;
	t_fork		*forks;
	t_philo		*philos;
}				t_table;

enum	e_mutex_action
{
	MUTEX_INIT,
	MUTEX_LOCK,
	MUTEX_UNLOCK,
	MUTEX_DESTROY
};

enum	e_thread_action
{
	THREAD_CREATE,
	THREAD_JOIN,
	THREAD_DETACH
};

void	check_arguments(t_table *table, char **av);
void	print_error(char *str);
void	*safe_malloc(size_t size);
void	mutex_handle(pthread_mutex_t *mutex, int e_mutex_action);
void	thread_handle(pthread_t *thread,
			void *(*start_routine) (void *),
			void *data,
			int e_thread_action);
void	data_init(t_table *table);
void	clean_table(t_table *table);
void	start_eating(t_table *table);

#endif