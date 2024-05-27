/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:30:31 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/27 14:54:54 by ruidos-s         ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;
typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;
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

void	check_arguments(char **av);
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