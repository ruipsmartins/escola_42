/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:08:20 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/04/23 12:40:28 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(char **av, int *fd)
{
	int	in_file;

	in_file = open(av[1], O_RDONLY);
	if (in_file == -1)
	{
		ft_printf("zsh: no such file or directory: %s\n", av[01]);
		exit(1);
	}
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	dup2(in_file, STDIN_FILENO);
	close(fd[1]);
	execve("/bin/zsh", (char *[]){"zsh", "-c", av[2], NULL}, NULL);
}

void	ft_parent(char **av, int *fd)
{
	int	out_file;

	wait(NULL);
	close(fd[1]);
	out_file = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(out_file, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(out_file);
	close(fd[0]);
	execve("/bin/zsh", (char *[]){"zsh", "-c", av[3], NULL}, NULL);
}
