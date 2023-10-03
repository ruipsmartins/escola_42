/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:28:06 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/08/01 11:50:22 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (src[count] != '\0' && count < n)
	{
		dest[count] = src[count];
		count ++;
	}
	while (count < n)
	{
		dest[count] = '\0';
		count ++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char a[15] = "hello world!";
	char b[15] = "teste01";
	char c[15] = "teste02";

	printf("%s", ft_strncpy(b, a, 3));
	printf("\n%s\n", strncpy(c, a, 3));
	
	printf("\n%s", ft_strncpy(b, a, 7));
	printf("\n%s\n", strncpy(c, a, 7));
	
	printf("\n%s", ft_strncpy(b, a, 15));
	printf("\n%s", strncpy(c, a, 15));
}*/
