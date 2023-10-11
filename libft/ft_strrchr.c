/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:17:46 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/10 16:00:39 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (s[i] != (char)c)
	{
		if (i < 0)
			return (NULL);
		i--;
	}
	return ((char *)&s[i]);
}

/* int	main(void)
{
	printf("strrchr: %s\n", strrchr("teste", 'e'));
	printf("ft_strrchr: %s\n", ft_strrchr( "101teste", 'e'));
	return (0);
} */