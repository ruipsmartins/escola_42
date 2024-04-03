/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:38:07 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/04/03 10:33:31 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void put_number(int n)
{
	char number;

	number = n + '0';

	if (n > 9)
	{
		put_number(n / 10);
		put_number(n % 10);
	}
	else
		write(1, &number, 1);
}

int main (void)
{
int n = 1;

	while (n<=100)
	{
		if (n % 3 == 0 && n % 5 == 0)
			write(1,"fizzbuzz", 8);
		else if (n % 3 == 0)
			write(1, "fizz", 4);
		else if (n % 5 == 0)
			write(1, "buzz", 4);
		else put_number(n);
		write(1, "\n", 1);
		n++;
	}

}
