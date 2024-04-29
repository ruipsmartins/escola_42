/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:36:42 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/22 15:52:57 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *s)
{
	int i = 0;

	while (s[i])
		write(1, &s[i++], 1);
}

int main (int argc, char **argv)
{
	int checker = 1;
	int i = 0;
	int j = 0;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			while (argv[2][j] && (argv[2][j] != argv[1][i]))
				j++;
			if (!argv[2][j])
				checker = 0;
			i++;
		}
		if (checker)
			ft_putstr(argv[1]);
	}
	
	write(1, "\n", 1);
	return 0;
}