/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:25:17 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/17 13:16:18 by ruidos-s         ###   ########.fr       */
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

char	*ft_create_line(int fd, char *buffer)
{
	char	*line;
	int		nbytes;
	int		i = 0;

	line = NULL;
	while (!ft_strchr(buffer, '\n'))
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes < 1)
			return (free(line), NULL);
		else
		{
			line = ft_strjoin(line, buffer);
			//"ABC\NDE"
		}
	}
	while (i < BUFFER_SIZE + 1)
	{
		buffer[i++] = 0;
	}
	return (line);
}
// já esta a funcionar mais ou menos sem leaks, falta arranjar quando nao ten \n na ultima linha e ver quando o BUFFERSIZE é de numeros diferentes,
// provavelmente o erro está quando eu estou a ver se o buffer tem um \n e depois nao estou a guardar o antigo e passa á frente