/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:08:29 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/16 11:54:50 by ruidos-s         ###   ########.fr       */
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
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	if ((size_t)dest - (size_t)src < len)
	{
		i = len - 1;
		while (i < len)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/* int	main(void)
{
	char	destino[20];
	char	original[] = "Olá, mundo!";

// Copia a string original para a string destino.
	ft_memmove(original + 2, original, sizeof(original));

  // Imprime a string destino.
	//printf("%s\n", destino);
	
	puts(original);
	return (0);
}
 */