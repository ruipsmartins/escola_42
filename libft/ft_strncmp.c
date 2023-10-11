/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:08:57 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/11 11:41:03 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

/* int	main(void)
{
	printf("strncmp: %d\n", strncmp("abc", "abc", 7));
	printf("ft_strncmp: %d\n", ft_strncmp("abc", "abc", 7));

	printf("strncmp: %d\n", strncmp("abcdef", "abc\375xx", 5));
    printf("ft_strncmp: %d\n", ft_strncmp("abcdef", "abc\375xx", 5));
	return (0);
} */