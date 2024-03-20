/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:47:25 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/20 19:04:37 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 0;
	unsigned char reversed = 0;
	
	while(i < 8)
	{
		reversed = (reversed<<1)|(octet & 1);
		octet>>=1;
		i++;
	}
	return (reversed);
}