/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:42:36 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/18 16:54:20 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv)
{
	
	if (argc == 2)
	{
		int i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				argv[1][i] = 'z' - argv[1][i] + 'a';
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] = 'Z' - argv[1][i] + 'A';
			write(1, &argv[1][i], 1);
			i++;
		}

	}
	write(1, "\n", 1);
	return 0;
}