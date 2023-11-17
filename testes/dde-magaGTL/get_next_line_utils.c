/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:40:01 by dde-maga          #+#    #+#             */
/*   Updated: 2023/11/07 13:40:17 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str && str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\n' && s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	if (s2[j] == '\n')
		new[i + j++] = '\n';
	new[i + j] = '\0';
	if (s1)
		free(s1);
	return (new);
}

void	ft_clean_buf(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < BUFFER_SIZE && buffer[i] != '\n')
	{
		buffer[i] = '\0';
		i++;
	}
	if (buffer[i] == '\n')
	{
		buffer[i] = '\0';
		i++;
		while (i < BUFFER_SIZE)
		{
			buffer[j] = buffer[i];
			buffer[i] = '\0';
			i++;
			j++;
		}
	}
}
