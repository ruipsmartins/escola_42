/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:11:06 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/04/24 13:13:08 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <errno.h>
# include <sys/wait.h>

void	perror(const char *str);
pid_t	wait(int *__stat_loc);
void	ft_child(char **av, int *fd, char **envp);
void	ft_parent(char **av, int *fd, char **envp);
int		check_infile(char **av, int *fd);
int		check_outfile(char **av, int *fd);

#endif