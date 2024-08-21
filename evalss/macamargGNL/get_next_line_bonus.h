/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:14:53 by macamarg          #+#    #+#             */
/*   Updated: 2024/05/10 11:15:17 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
//standard C libraries

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

//project prototypes

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_is_newline(char *str);
void	*ft_clean(char *current_line, char *read_content);

#endif