/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:05:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/07 11:11:56 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	char str1[] = "Hello World!";
	char str2[20];

	puts("str1 before memmove \n"); 
	puts(str1); 

	/* Copies contents of str2 to sr1 */
	ft_memmove(str1, str2, sizeof(str1)); 

	puts("str2 after memmove "); 
	puts(str1); 

	return (0);
}
