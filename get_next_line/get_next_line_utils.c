/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:25:17 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/16 16:56:44 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	size_t	total;

	total = nmemb * size;
	dest = malloc(total);
	if (!dest)
		return (0);
	while (total--)
		((char *)dest)[total] = '\0';
	return (dest);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}

char	*ft_strjoin(char *old_str, char *buffer)
{
	char		*new_str;
	size_t		i;
	size_t		j;

	if (!old_str || !buffer)
		return (free(old_str), NULL);
	new_str = malloc(ft_strlen(old_str) + ft_strlen(buffer) + 1);
	if (!new_str)
		return (free(old_str), NULL);
	i = 0;
	while (old_str[i])
		new_str[i++] = old_str[i];
	free(old_str);
	j = 0;
	while (buffer[j] && buffer[j - 1] != '\n')
		new_str[i + j++] = buffer[j];
	new_str[i + j] = '\0';
	return (new_str);
}

char	*ft_create_line(int fd, char *buffer)
{
	char	*line;
	int		nbytes;
	int		i = 0;
	line = malloc(1 * sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	while (!ft_strchr(buffer, '\n'))
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes < 1)
			return (NULL);
		else
		{
			line = ft_strjoin(line, buffer);
		}
	}
	while(i < BUFFER_SIZE + 1)
	{
		buffer[i++] = 0;
	}
	return (line);
}
