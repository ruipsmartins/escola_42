/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:37:23 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/07 18:10:40 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	sizesrc;

	sizesrc = ft_strlen(src);
	if (!dest || !src)
		return (0);

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size -1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}

	return (sizesrc);
}

/* int	main(void)
{
	char	src[] = "Hello, World!";
	char	dest[15];
	int		len = ft_strlcpy(dest, src, sizeof(dest));

	printf("sizeof(dest):%ld\n", sizeof(dest));
	printf("String copiada: %s\n", dest);
	printf("Tamanho da string de origem: %d\n", len);

	return (0);
}
 */