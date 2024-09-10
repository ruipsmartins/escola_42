/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:09:13 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/26 17:35:41 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_gnl
{
	char			*buf;
	struct s_gnl	*next;
}				t_gnl;

char	*get_next_line(int fd);
void	create_list(t_gnl **lnklist, int fd);
char	*cpy_line(t_gnl *lnklist);
void	prep_next_line(t_gnl **lnklist);
int		end_line(t_gnl *list);
void	lstadd_back(t_gnl **lst, t_gnl *new);
t_gnl	*lstlast(t_gnl *lst);
size_t	list_len(t_gnl *lnklist);
void	free_content(t_gnl **lnklist, t_gnl *char_n_used);

#endif
