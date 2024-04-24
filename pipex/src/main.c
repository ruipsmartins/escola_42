/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:49 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/04/24 12:20:41 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int	main(int ac, char **av)
{
	int	fd[2];
	int	pid;

	if (ac == 5)
	{
		pid = fork();
		if (pid < 0)
			exit(1);
		if (pipe(fd) < 0)
			exit(1);
		if (pid == 0)
			ft_child(av, fd);
		else
			ft_parent(av, fd);
	}
	else
	{
		ft_printf("Program must be executed like this example: \n");
		ft_printf("./pipex infile \"ls -l\" \"wc -l\" outfile\n");
		return (1);
	}
	return (0);
}
