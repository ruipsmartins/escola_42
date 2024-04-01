/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:39:04 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/08/13 09:30:26 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	short	i;

	i = 0;
	if (ac == 1)
	{
		while (av[0][i] != 0)
			write(1, &av[0][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}