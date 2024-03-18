/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:42:20 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/25 10:29:32 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_number(int number)
{
	char number_char[1];

	number_char[0] = number + '0';
	if (number < 10)
		write(1, number_char, 1);
	else
	{
		number_char[0]= (number/10) + '0';
		write(1, number_char, 1);
		number_char[0]= (number%10) + '0';
		write(1, number_char, 1);
	}
	
	write(1, "\n", 1);
}

int	main(void)
{
	int	i;

	i = 0;
	while (i < 101)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz\n",9);
		else if (i % 3 == 0)
			write(1, "fizz\n", 5);
		else if (i % 5 == 0)
			write(1, "buzz\n", 5);
		else
			ft_write_number(i);
		i++;
	}
	return (0);
}