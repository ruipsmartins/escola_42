/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:07:46 by tjorge-d          #+#    #+#             */
/*   Updated: 2023/11/08 17:07:50 by tjorge-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_zeros(char *buffer, char mode);
int		ft_refresh_buffer(char *line, char *buffer, int fd);
int		ft_needed_lenght(char *str, char mode);
char	*get_next_line(int fd);
char	*ft_line_adder(char *line, char *buffer);
char	*ft_line_creator(char *buffer, int fd);

#endif
