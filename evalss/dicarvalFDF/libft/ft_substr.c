/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:06:56 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/14 10:37:30 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	st_len;
	size_t	subst_len;

	if (s == NULL)
		return (NULL);
	st_len = ft_strlen(s);
	if (start >= st_len)
		return (ft_strdup(""));
	subst_len = st_len - start;
	if (len > subst_len)
		len = subst_len;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
