/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:08:20 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/04/24 15:14:03 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

int	check_infile(char **av, int *fd)
{
	if (access(av[1], F_OK) == -1)
	{
		ft_printf("zsh: no such file or directory: %s\n", av[1]);
		close_fds(fd);
		return (1);
	}
	if (access(av[1], R_OK) == -1)
	{
		ft_printf("permission denied: %s\n", av[1]);
		close_fds(fd);
		return (1);
	}
	return (0);
}

int	check_outfile(char **av, int *fd)
{
	if (access(av[4], F_OK) != -1)
	{
		if (access(av[4], W_OK) == -1)
		{
			ft_printf("permission denied: %s\n", av[4]);
			close_fds(fd);
			return (1);
		}
	}
	return (0);
}

void	ft_child(char **av, int *fd, char **envp)
{
	int	in_file;

	if (check_infile(av, fd))
		exit(1);
	in_file = open(av[1], O_RDONLY);
	if (in_file == -1)
		exit(1);
	dup2(fd[1], STDOUT_FILENO);
	dup2(in_file, STDIN_FILENO);
	close(in_file);
	close_fds(fd);
	execve("/bin/bash", (char *[]){"bash", "-c", av[2], NULL}, envp);
}

void	ft_parent(char **av, int *fd, char **envp)
{
	int	out_file;

	wait(NULL);
	if (check_outfile(av, fd))
		exit(1);
	out_file = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (out_file == -1)
		exit (1);
	dup2(out_file, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(out_file);
	close_fds(fd);
	execve("/bin/bash", (char *[]){"bash", "-c", av[3], NULL}, envp);
}
