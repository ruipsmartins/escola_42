/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:08:20 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/04/24 11:32:19 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int check_infile(char **av)
{
	if (access(av[1], F_OK) == -1)
	{
		ft_printf("zsh: no such file or directory: %s\n", av[1]);
		return (1);
	}
	if (access(av[1], R_OK) == -1)
	{
		ft_printf("zsh: permission denied: %s\n", av[1]);
		return (1);
	}
	return (0);
}

int check_outfile(char **av)
{
	if (access(av[4], F_OK) != -1)
	{
		if (access(av[4], W_OK)== -1)
		{
			ft_printf("zsh: permission denied: %s\n", av[4]);
			return (1);
		}
	}
	return (0);
}

void	ft_child(char **av, int *fd)
{
	int	in_file;

	if(check_infile(av))
		exit(1);
	in_file = open(av[1], O_RDONLY);
	if (in_file == -1)
	{
		perror("open infile");
		exit(1);
	}
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	dup2(in_file, STDIN_FILENO);
	close(in_file);
	close(fd[1]);
	execve("/bin/zsh", (char *[]){"zsh", "-c", av[2], NULL}, NULL);
}

void	ft_parent(char **av, int *fd)
{
	int	out_file;

	wait(NULL);
	if(check_outfile(av))
		exit(1);
	close(fd[1]);
	out_file = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (out_file == -1)
	{
		perror("open outfile");
		exit(1);
	}
	dup2(out_file, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(out_file);
	close(fd[0]);
	execve("/bin/zsh", (char *[]){"zsh", "-c", av[3], NULL}, NULL);
}
