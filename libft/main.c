/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:05:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/20 15:05:18 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <ctype.h>

char	ft_teste(unsigned int i, char c)
{
	i = 32;
	if (c >= 'a' && c <= 'z')
	{
		c -= i;
	}
	return (c);
}

int	main(void)
{
	char	*str = "hello world!!";
	char	*result;

	result = ft_strmapi(str, ft_teste);
	printf("ft_strmapi: %s\n", result);
	free(result);
	return (0);
}
