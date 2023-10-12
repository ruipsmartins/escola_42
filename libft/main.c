/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:05:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/12 14:55:42 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

int	main(void)
{
	char	*b = "isto e uma mensagem";
	char	*lil = "to";
	size_t	len = 4;

	printf("strnstr: %s\n", strnstr(b, lil, len));
	printf("ft_strnstr: %s\n", ft_strnstr(b, lil, len));

	return (0);
}
