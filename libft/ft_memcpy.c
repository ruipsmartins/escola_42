/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:48:49 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/16 11:51:13 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The  memcpy()  function  copies  n  bytes
 from memory area src to memory area dest.
The memory areas must not overlap.  */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	char	src[] = "Hello World!";
	char	dest[20];

// Copia a string, incluindo o caractere nulo de terminação;
    ft_memcpy(dest, src, ft_strlen(src) + 1);

	printf("Conteúdo da área de destino: %s\n", dest);
	return (0);
} */
