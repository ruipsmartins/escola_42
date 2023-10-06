/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:05:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/06 12:24:59 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	char str1[] = "Geeks"; // Array of size 100 
	char str2[] = "Quiz"; // Array of size 5 

	puts("str1 before memmove "); 
	puts(str1); 

	/* Copies contents of str2 to sr1 */
	memmove(str1, str2, sizeof(str2)); 

	puts("\nstr1 after memmove "); 
	puts(str1); 

	return (0);
}
