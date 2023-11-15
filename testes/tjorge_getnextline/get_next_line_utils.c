/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:44:25 by tjorge-d          #+#    #+#             */
/*   Updated: 2023/11/02 16:44:29 by tjorge-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_zeros(char *buffer, char mode)
{
	int	i;

	i = 0;
	if (mode == 'i')
	{
		while (buffer[i] == 0 && i < BUFFER_SIZE)
			i++;
	}
	if (mode == 'c')
	{
		while (i <= BUFFER_SIZE)
			buffer[i++] = 0;
	}
	return (i);
}

int	ft_needed_lenght(char *str, char mode)
{
	int	i;
	int	j;

	j = 0;
	if (!str)
		return (0);
	if (mode == 'b')
		j = ft_zeros(str, 'i');
	i = j;
	while (str[i] != 0)
	{
		if (str [i] == '\n' || str[i] == '\0')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i - j);
}

char	*ft_line_adder(char *line, char *buffer)
{
	char	*new_line;
	int		lenght;
	int		i;
	int		j;

	lenght = ft_needed_lenght(buffer, 'b') + ft_needed_lenght(line, 'l');
	new_line = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	new_line[lenght] = '\0';
	i = -1;
	while (line[++i])
		new_line[i] = line[i];
	free(line);
	j = ft_zeros(buffer, 'i');
	while (buffer[j] && i < lenght)
	{
		new_line[i] = buffer[j];
		buffer[j++] = 0;
		i++;
	}
	return (new_line);
}

int	ft_refresh_buffer(char *line, char *buffer, int fd)
{
	int	bytes;
	int	i;
	int	j;

	j = -1;
	i = ft_zeros(buffer, 'i');
	while (line[++j] != '\0')
	{
		if (line[j] == '\n')
			return (1);
	}
	if (i == BUFFER_SIZE)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0 && j > 0)
			return (1);
		if (bytes == 0)
		{
			free(line);
			return (-1);
		}
	}
	return (0);
}

char	*ft_line_creator(char *buffer, int fd)
{
	char	*line;
	int		checker;

	checker = 0;
	line = (char *)malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	while (checker != 1)
	{
		checker = ft_refresh_buffer(line, buffer, fd);
		if (checker == 1)
			return (line);
		if (checker == -1)
			return (NULL);
		line = ft_line_adder(line, buffer);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}
