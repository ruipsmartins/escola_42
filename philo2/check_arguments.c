/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:01:52 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/05/27 14:59:31 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_atoi(char *str)
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
int	check_arg_content(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
void	check_input_errors(char **av)
{
	if (av[5] && av[5][0] == '0')
		exit(EXIT_SUCCESS);
	if (ft_atoi(av[1]) > 200 || ft_atoi(av[1]) <= 0
		|| check_arg_content(av[1]) == 1)
		print_error("Invalid philosophers number\n" );
	if (ft_atoi(av[2]) <= 0 || check_arg_content(av[2]) == 1)
		print_error("Invalid time to die\n");
	if (ft_atoi(av[3]) <= 0 || check_arg_content(av[3]) == 1)
		print_error("Invalid time to eat\n" );
	if (ft_atoi(av[4]) <= 0 || check_arg_content(av[4]) == 1)
		print_error("Invalid time to sleep\n" );
	if (av[5] && (ft_atoi(av[5]) < 0 || check_arg_content(av[5]) == 1))
		print_error("Invalid number of meals\n");
}

void	check_arguments(char **av)
{
	int	i;

	i = 0;
	i++;
	check_input_errors(av);

}
