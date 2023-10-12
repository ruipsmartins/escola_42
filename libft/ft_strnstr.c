/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:38:25 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/12 15:07:36 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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