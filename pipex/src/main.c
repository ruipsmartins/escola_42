/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:49 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/04/22 12:40:25 by ruidos-s         ###   ########.fr       */
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
			close(fd[0]);	// Fecha a extremidade de leitura do pipe
			out_file = open(av[4], O_WRONLY | O_CREAT, 0777);
			
			dup2(out_file, STDOUT_FILENO);	// Redireciona a saída padrão para o arquivo
			execve("/bin/bash", (char *[]){"bash", "-c", av[2], NULL}, NULL);
			fd[1] = out_file;
			close(out_file);	// Fecha o arquivo
			close(fd[1]);	// Fecha a extremidade de escrita do pipe
			exit(0);

		}
		else if (pid != 0)
		{
			close(fd[1]);	// Fecha a extremidade de escrita do pipe
			ft_printf("%s", fd[0]);
			close(fd[0]);	// Fecha a extremidade de leitura do pipe
			wait(NULL);
		}	
			ft_printf("programa acabado! \n");
	}
	return (0);
}
