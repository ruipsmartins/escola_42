/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:37:54 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/02/10 07:52:16 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	main (void)
{
	int n = 0;
	char *s = "Hello World";

	n = ft_strlen("ola mundo");
	ft_printf("%s %d\n", s, n);
	return 0;
}