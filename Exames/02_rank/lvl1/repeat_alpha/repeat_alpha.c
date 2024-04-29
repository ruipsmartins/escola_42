/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:09:20 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/18 15:27:58 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		int count;
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z' )
			{
				count = argv[1][i] - 'a';
				while (count >= 0)
				{
					write(1, &argv[1][i], 1);
					count--;
				}
			}
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z' )
			{
				count = argv[1][i] - 'A';
				while (count >= 0)
				{
					write(1, &argv[1][i], 1);
					count--;
				}
			}
			else 
				write(1, &argv[1][i], 1);

			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}