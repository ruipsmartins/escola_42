/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:38:09 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/06/04 09:02:48 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int		number;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	number = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number * sign);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		print_error("gettimeofday() error", true);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

void	clean_table(char *str, t_table *table, bool sair)
{
	int	i;
	int	philo_num;

	philo_num = table->num_of_philos;
	i = 0;
	if (str)
		print_error(str, sair);
	safe_mutex(&table->write_lock, MUTEX_DESTROY);
	safe_mutex(&table->meal_lock, MUTEX_DESTROY);
	safe_mutex(&table->dead_lock, MUTEX_DESTROY);
	while (i < philo_num)
	{
		safe_mutex(&table->forks[i].fork_thread, MUTEX_DESTROY);
		i++;
	}
	if (table->philos)
		free(table->philos);
	if (table->forks)
		free(table->forks);
}
