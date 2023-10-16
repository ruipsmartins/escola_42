/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:38:25 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/16 12:33:21 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strnstr() function locates the first occurrence
of the null-terminated string little in the string big,
where not more than len characters are searched.  
Characters that appear after a ‘\0’ character are not searched.
Since the strnstr() function is a
FreeBSD specific API, it should only be used 
when portability is not a concern. */
//Utility functions from BSD systems (libbsd, -lbsd)

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	if (!*big)
		return (NULL);
	while (i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}

/* #include "libft.h"
#include <bsd/string.h>

int	main(void)
{
	char	*b = "isto e uma mensagem";
	char	*lil = "to";
	size_t	len = 4;

	printf("strnstr: %s\n", strnstr(b, lil, len));
	printf("ft_strnstr: %s\n", ft_strnstr(b, lil, len));

	return (0);
} */