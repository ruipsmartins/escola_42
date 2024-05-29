/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:38:09 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/29 17:24:58 by ruidos-s         ###   ########.fr       */
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
	int	number;
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
		printf("gettimeofday() error\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_error(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str) + 1);
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

void	clean_table(char *str, t_table *table, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
		printf("%s\n", str);
	safe_mutex(&table->write_lock, MUTEX_DESTROY);
	safe_mutex(&table->meal_lock, MUTEX_DESTROY);
	safe_mutex(&table->dead_lock, MUTEX_DESTROY);

	/* pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->meal_lock);
	pthread_mutex_destroy(&table->dead_lock); */
	while (i < table->philos[0].num_of_philos)
	{
		safe_mutex(&forks[i], MUTEX_DESTROY);
		//pthread_mutex_destroy(&forks[i]);
		i++;
	}
}



/* void	clean_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philos)
	{
		safe_mutex(&table->forks[i].fork, MUTEX_DESTROY);
		i++;
	}
	free(table->philos);
	free(table->forks);
} */
