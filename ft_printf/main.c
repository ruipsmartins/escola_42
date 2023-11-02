/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:33:36 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/02 10:34:57 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	int	count;

	count = printf("hello world!\n");
	printf("count = %d\n", count);
	ft_putstr_fd("hello putstr\n", 1);
	return (0);
}
