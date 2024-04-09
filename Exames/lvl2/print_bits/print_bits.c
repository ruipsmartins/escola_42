/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:56:14 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/04/09 14:15:27 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

int main ()
{

	print_bits(42);

	return 0;
}