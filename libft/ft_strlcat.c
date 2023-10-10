/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:12:46 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/10 12:45:19 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size <= ft_strlen(dest))
		return (ft_strlen(src) + size);
	i = 0;
	j = ft_strlen(dest);
	while (src[i] != '\0' && j + 1 < size)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[i]));
}

/* int	main(void)
{
	char dest[20] = "Hello, ";
    char src[] = "World!";

    size_t len = ft_strlcat(dest, src, sizeof(dest));

    printf("String concatenada: %s\n", dest);
    printf("Tamanho da string resultante: %zu\n", len);
	return (0);
} */