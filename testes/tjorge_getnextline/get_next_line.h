/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:30:17 by tjorge-d          #+#    #+#             */
/*   Updated: 2023/11/15 10:05:24 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
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
