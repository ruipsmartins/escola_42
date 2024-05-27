/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:38:09 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/20 14:46:04 by ruidos-s         ###   ########.fr       */
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

void	clean_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philos)
	{
		mutex_handle(&table->forks[i].fork, MUTEX_DESTROY);
		i++;
	}
	free(table->philos);
	free(table->forks);
}
