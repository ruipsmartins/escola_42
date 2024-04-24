/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:49 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/04/24 14:17:22 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	pid;

	if (ac == 5)
	{
		if (pipe(fd) < 0)
			exit(1);
		pid = fork();
		if (pid < 0)
			exit(1);
		if (pid == 0)
			ft_child(av, fd, envp);
		else
			ft_parent(av, fd, envp);
	}
	else
	{
		ft_printf("Program must be executed like this example: \n");
		ft_printf("./pipex infile \"ls -l\" \"wc -l\" outfile\n");
		return (1);
	}
	return (0);
}
