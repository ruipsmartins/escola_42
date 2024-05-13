/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:30:31 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/13 17:38:26 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdbool.h>

typedef struct s_fork
{
	pthread_mutex_t fork;
	int				fork_id;
	
}					t_fork;


typedef struct s_philo
{
	int		id;
	long	meals_counter;
	bool	full;
	long	last_meal_time;
	t_fork	*left_fork;
	t_fork	*right_fork;
	pthread_t thread_id;
	
}		t_philo;

typedef struct s_table
{
	long		philo_number;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nbr_limit_meals;
}				t_table;






#endif