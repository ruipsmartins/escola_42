/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:31:31 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/06 10:43:56 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	ft_memset(s, '\0', len);
}

/* 
int	main(void)
{
	char	str[50] = "Hello World!";

	printf("antes do ft_bzero: %s\n", str);
	ft_bzero(str + 5, 5);
	printf("depois do ft_bzero: %s\n", str);
	return (0);
}
 */