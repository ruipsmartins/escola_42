/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:05:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/10 16:48:45 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	main(void)
{
	printf("strncmp: %d\n", strncmp("abc", "abc", 7));
	printf("ft_strncmp: %d\n\n", ft_strncmp("abc", "abc", 7));
	
	printf("strncmp: %d\n", strncmp("abcdef", "abc\375xx", 5));
	printf("ft_strncmp: %d\n", ft_strncmp("abcdef", "abc\375xx", 5));
	return (0);
}
