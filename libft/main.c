/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:05:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/12 16:59:54 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

int	main(void)
{
	int		*array1;
	int		*array2;
	size_t	num_elements = 10;
	size_t	i;

    // Alocando array1 com 5 inteiros e inicializando com zeros
	array1 = (int *)calloc(num_elements, sizeof(int));
	array2 = (int *)ft_calloc(num_elements, 8);

	if (array1 == NULL)
		printf("Falha na alocação de memória array1.");
	if (array2 == NULL)
		printf("Falha na alocação de memória array2.");


    // Imprimindo os elementos do array1
	i = 0;
	printf("Array1 com zeros: ");
	while (i < num_elements)
	{
		printf("%d ", array1[i]);
		i++;
	}
	printf("\nArray2 com zeros: ");
	i = 0;
	while (i < num_elements)
	{
		printf("%d ", array2[i]);
		i++;
	}
    // Liberando a memória alocada
	free(array1);
	free(array2);
	return (0);
}
