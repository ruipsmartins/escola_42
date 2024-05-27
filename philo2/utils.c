/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:38:09 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/27 17:53:36 by ruidos-s         ###   ########.fr       */
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

void	print_error(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str) + 1);
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
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
