/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:49 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/04/21 16:58:50 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int	main(int ac, char **av)
{
	int fd[2];
	int out_file;
	int pid;

	if (ac != 5)
	{
		perror("wrong args, ex: ./pipex infile \"ls -l\" \"wc -l\" outfile");
		return (1);
	}
	else if (ac == 5)
	{

		pipe(fd);
		pid = fork();

		if (pid == 0)
		{
			// Filho
			close(fd[0]); // Fecha a extremidade de leitura do tubo
			out_file = open(av[4], O_WRONLY | O_CREAT, 0777);
			dup2(out_file, STDOUT_FILENO); // Redireciona a saída padrão para o arquivo
			close(out_file); // Fecha o arquivo
			close(fd[1]); // Fecha a extremidade de escrita do tubo
			execve("/bin/bash", (char *[]){"bash", "-c", av[2], NULL}, NULL);
			exit(0);

		}
		else if (pid != 0)
		{
			close(fd[0]);
			close(fd[1]);
			wait(NULL);
			ft_printf("programa acabado \n");
		}	
	}
	return (0);
}
