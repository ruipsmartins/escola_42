/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:49 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/04/21 12:28:26 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int	main(int ac, char **av)
{
	int	i;
	int fd[2];

	if (ac != 5)
	{
		perror("wrong args, ex: ./pipex infile \"ls -l\" \"wc -l\" outfile");
		return (1);
	}
	else if (ac == 5)
	{
		i = 1;
		pipe(fd);
		int id = fork();

		if (id == 0)
		{
			execve("/bin/bash", (char *[]){"bash", "-c", av[2], NULL}, NULL);
		}
		else if (id != 0)
		{
			wait(NULL);
			while (i < ac)
			{
				ft_printf(av[i]);
				ft_printf("\n");
				i++;
			}
		}	
	}
	return (0);
}
