/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:43:15 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/16 12:00:11 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The  strdup()  function returns a pointer to a new string which is a 
duplicate of the string s.  Memory for the new string is 
obtained with malloc(3), and can be freed with free(3). */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	dup = malloc (ft_strlen(s) + 1);
	if (!dup)
		return (0);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/* int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = strdup("um");
	str2 = ft_strdup("dois");
	printf("%s %s\n", str1, str2);
	free(str1);
	free(str2);
	return (0);
}
 */