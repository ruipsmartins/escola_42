/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:32:33 by bruno             #+#    #+#             */
/*   Updated: 2024/04/06 18:46:18 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	ret = 0;
	if (s1 && set)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		ret = (char *)malloc(sizeof(char) * (j - i + 1));
		if (ret == NULL)
			return (NULL);
		if (ret)
			ft_strlcpy(ret, &s1[i], j - i + 1);
	}
	return (ret);
}
