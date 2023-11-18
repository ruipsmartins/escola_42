/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:25:17 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/18 09:51:32 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *old_str, char *buffer)
{
	char		*new_str;
	size_t		i;
	size_t		j;

	new_str = malloc(ft_strlen(old_str) + ft_strlen(buffer) + 1);
	if (!new_str)
		return (free(old_str), NULL);
	i = 0;
	while (old_str && old_str[i])
	{
		new_str[i] = old_str[i];
		i++;
	}
	free(old_str);
	j = 0;
	while (buffer[j])
	{
		new_str[i + j] = buffer[j];
		if (buffer[j] == '\n' && ++j)
			break ;
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

void	ft_clean_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	//meter os primeiros caracteres ate ao \n a 0
	while (i < BUFFER_SIZE && buffer[i] != '\n')
		buffer[i++] = 0;
	// se o buffer[i] for \n entao meter 0 e comessar a copiar para traz e meter os ultimos a 0
	if (buffer[i] == '\n')
	{
		buffer[i++] = 0;
		while (i < BUFFER_SIZE + 1)
		{
			buffer[j] = buffer[i];
			buffer[i] = 0;
			i++;
			j++;
		}
	}
}

char	*ft_create_line(int fd, char *buffer)
{
	char	*line;

	line = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		ft_clean_buffer(buffer);
		if (line[ft_strlen(line) - 1] == '\n')
			return (line);
	}
	return (line);
}
