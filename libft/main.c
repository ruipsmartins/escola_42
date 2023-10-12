/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:05:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/12 13:38:23 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

int	main(void)
{
	char	*b = "isto e uma mensagem de teste";
	char	*lil = "uma mensagem";
	size_t	len = 20;

	printf("strnstr: %s\n", strnstr(b, lil, len));
	printf("ft_strnstr: %s\n", ft_strnstr(b, lil, len));

	return (0);
}
