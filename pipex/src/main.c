/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:49 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/04/22 14:42:58 by ruidos-s         ###   ########.fr       */
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
			dup2(fd[1], STDOUT_FILENO);	// Redireciona a saída padrão para o pipe
			close(fd[1]);	// Fecha a extremidade de escrita do pipe
			execve("/bin/zsh", (char *[]){"zsh", "-c", av[2], NULL}, NULL);
		}
		else if (pid != 0)
		{
			wait(NULL);
			close(fd[1]);	// Fecha a extremidade de escrita do pipe
			out_file = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			dup2(out_file, STDOUT_FILENO);
			dup2(fd[0], STDIN_FILENO);
			close(out_file);	// Fecha o arquivo
			close(fd[0]);	// Fecha a extremidade de leitura do pipe
			execve("/bin/zsh", (char *[]){"zsh", "-c", av[3], NULL}, NULL);
		}	
			//ft_printf("programa acabado! \n");
	}
	return (0);
}
