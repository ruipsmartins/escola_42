/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:50:39 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/20 18:42:54 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bit;

	while(i--)
	{
		bit = (octet >> i & 1) + 48;
		write(1, &bit, 1);
	}
}


int main ()
{
	print_bits(42);
	printf("\n");
	return 0;
}