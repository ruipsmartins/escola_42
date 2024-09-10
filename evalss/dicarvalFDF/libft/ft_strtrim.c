/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:27:52 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/14 10:37:29 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*strtrim;
	int		i;
	int		j;
	int		trim_len;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] && ft_is_set(str[i], set))
		i++;
	j = ft_strlen(str) - 1;
	while (j && ft_is_set(str[j], set))
		j--;
	trim_len = j - i + 2;
	if (j < i)
	{
		strtrim = ft_calloc(1, 1);
		return (strtrim);
	}
	else
		strtrim = malloc(sizeof(char) * trim_len);
	if (strtrim == NULL)
		return (NULL);
	ft_strlcpy(strtrim, &str[i], trim_len);
	return (strtrim);
}
//line 34 - checks the beggining of the string
//line 37 - checks the end of the string
//line 39 - + 2 because we want the lenght, j and i starts at 0 so...
//line 46 - malloc of the trimmed string
//line 49 - copy of trimmed string
