/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:39:56 by macamarg          #+#    #+#             */
/*   Updated: 2024/06/04 09:44:03 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			i++;
		}
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;
	char	*s_final;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s_final = (char *)malloc(len_s1 + len_s2 + 1);
	if (s_final == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (i++ < (len_s1 -1))
		s_final[i] = s1[i];
	while (j++ < (len_s2 - 1))
	{
		s_final[i] = s2[j];
		i++;
	}
	s_final[i] = '\0';
	if (s1)
		free (s1);
	return (s_final);
}

int	ft_is_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str [i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
