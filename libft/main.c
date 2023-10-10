/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:05:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/10 16:00:05 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	main(void)
{
	printf("strrchr: %s\n", strrchr("teste", 'e'));
	printf("ft_strrchr: %s\n", ft_strrchr( "101teste", 'e'));
	return (0);
}
