/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:24:29 by brfernan          #+#    #+#             */
/*   Updated: 2024/06/17 17:42:23 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_fds_exit(int *fd, char *str)
{
	close(fd[0]);
	close(fd[1]);
	error(str, 1);
}

void	error(char *str, int code)
{
	write(2, "bash: ", 6);
	perror(str);
	exit(code);
}

void	error2(char *str, int code, int *fd)
{
	char	**new;

	close(fd[0]);
	close(fd[1]);
	new = ft_split(str, ' ');
	write(2, new[0], ft_strlen(new[0]));
	write(2, ": command not found\n", 20);
	freecoms(new);
	exit(code);
}
