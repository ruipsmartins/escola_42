/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:47:25 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/21 11:41:50 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<stdio.h>
#include<unistd.h>

void print_bits(unsigned char octet)
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

}

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 0;
	unsigned char reversed = 0;
	
	while(i < 8)
	{
		reversed = (reversed * 2) + (octet % 2);
		octet/=2;
		i++;
	}
	print_bits(reversed);
	return (reversed);
}



int main()
{
    unsigned char byte = 38;

	print_bits(byte);
    unsigned char byte_invertido = reverse_bits(byte);

    return 0;
}