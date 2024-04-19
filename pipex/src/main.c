/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:49 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/04/19 17:12:01 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int	main(int ac, char **av)
{
	int	i;

	if (ac != 5)
	{
		perror("wrong args, ex: ./pipex infile \"ls -l\" \"wc -l\" outfile");
		return (1);
	}
	else if (ac == 5)
	{
		i = 1;
		execve("/bin/sh", (char *[]){"sh", "-c", av[2], NULL}, NULL);
		while (i < ac)
		{
			ft_printf(av[i]);
			ft_printf("\n");
			i++;
		}
	}
	return (0);
}
