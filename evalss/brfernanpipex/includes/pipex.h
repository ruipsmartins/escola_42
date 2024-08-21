/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:58:29 by brfernan          #+#    #+#             */
/*   Updated: 2024/06/18 10:07:47 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define WRONG "wrong: ./pipex <file1> <cmd1> <cmd2> <file2>"
# define WRITE 1
# define READ 0

char	*find_path(char **envp, char *com);
void	error(char *str, int code);
void	error2(char *str, int code, int *fd);
void	freecoms(char **com);
bool	execute(char *arg, char **envp);
void	close_fds_exit(int *fd, char *str);

#endif