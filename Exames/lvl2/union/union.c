/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:03:02 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/22 15:35:08 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main (int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		int j = -1;

		while (argv[1][i])
			i++;
		while (argv[2][++j])
		{
			argv[1][i] = argv[2][j];
			i++;
		}
		i = 0;
		while (argv[1][i])
		{
			int checker = 1;
			j = 0;
			while (j < i)
			{
				if (argv[1][i] == argv[1][j])
				{
					checker = 0;
				}
				j++;
			}
			if (checker)
				write(1, &argv[1][i], 1);
			i++;
		}
	
	}
	write(1, "\n", 1);
	return 0;
}