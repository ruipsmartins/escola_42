/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:30:31 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/31 15:23:24 by ruidos-s         ###   ########.fr       */
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

typedef struct s_forks
{
	int				fork_id;
	pthread_mutex_t	fork_thread;
}					t_fork;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			start_time;
	int				*dead;
	t_fork			*first_fork;
	t_fork			*second_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;
typedef struct s_table
{
	int				num_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_times_to_eat;
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
	t_fork			*forks;
}					t_table;



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
void	print_error(char *str, bool sair);
void	*safe_malloc(size_t size);
void	safe_mutex(pthread_mutex_t *mutex, int e_mutex_action);
void	safe_thread(pthread_t *thread,
			void *(*start_routine) (void *),
			void *data,
			int e_thread_action);
int		ft_atoi(char *str);
void	data_init(t_table *table, t_philo *philos, t_fork *forks, char **av);
size_t	get_current_time(void);
int		start_dinner(t_table *table, t_fork *forks);
void	clean_table(char *str, t_table *table);

#endif