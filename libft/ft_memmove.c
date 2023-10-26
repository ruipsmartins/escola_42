/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:08:29 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/26 16:30:15 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The  memmove()  function  copies  n  bytes from memory area 
src to memory area dest.  The memory areas may overlap: copying takes
place as though the bytes in src are first copied
into a temporary array that does not overlap src or dest,  and  the  bytes  are
then copied from the temporary array to dest. */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	ptr = (unsigned char*)dest;
	ptr2 = (unsigned char*)src;
	i = 0;
	if (ptr == NULL && ptr2 == NULL)
		return (NULL);
	if (ptr2 < ptr)
		while (++i <= len)
			ptr[len - i] = ptr2[len - i];
	else
		while (len-- > 0)
			*(ptr++) = *(ptr2++);
	return (dest);
}



/*
#include <stdio.h>

int	main(void)
{
	char	original[] = "hello, world!";
	char	destino[5];

// Copia a string original para a string destino.
	//ft_memmove(destino, original, 20);
	printf("(size_t)destino: %zu\n",(size_t)destino);
	printf("(size_t)original: %zu\n",(size_t)original);
	memmove(destino, original, ft_strlen(original));
  // Imprime a string destino.
	
	printf("original: %s\n", original);
	printf("destino: %s\n", destino);
	return (0);
}
*/