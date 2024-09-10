/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:17:28 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/14 10:37:23 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*nwstr;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	nwstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen (s2) + 1));
	if (nwstr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		nwstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		nwstr[i + j] = s2[j];
		j++;
	}
	nwstr[i + j] = '\0';
	return (nwstr);
}
