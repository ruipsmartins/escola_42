/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:05:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/20 16:41:25 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <ctype.h>

void	ft_teste(unsigned int i, char*c)
{

	if (*c >= 'a' && *c <= 'z')
	{
		*c -= 32;
		printf("i = %i, Char: %c\n", i, *c);
	}
}

int	main(void)
{
	char	str[] = "hello world!!";

	printf("Original String: %s\n", str);
	ft_striteri(str, ft_teste);
	printf("Modified String: %s\n", str);
	return (0);
}
