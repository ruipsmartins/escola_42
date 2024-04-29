/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:43:40 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/21 13:04:34 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>


/* void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet % 2) + '0';
		octet /=2;
		write(1, &bit, 1);
	}
		write(1, "\n", 1);

} */
void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
		write(1, "\n", 1);

}

unsigned char	swap_bits(unsigned char octet)
{
	int y = 4;
	unsigned char temp = 0;
	print_bits(octet);
	octet = (octet >> 4) | (octet << 4);
	//octet = (octet * 4) + (octet / 4);
	print_bits(octet);
	return octet;
}
int main()
{
    unsigned char byte = 65;

    unsigned char swaped = swap_bits(byte);

    return 0;
}