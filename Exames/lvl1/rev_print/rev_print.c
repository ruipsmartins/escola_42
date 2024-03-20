/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:30:27 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/18 15:37:19 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *s)
{
	int count = 0;

	while(s[count])
		count++;
	return count;
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		int count = ft_strlen(argv[1]) - 1;

		while (count >= 0)
		{
			write(1, &argv[1][count], 1);
			count--;
		}
	}
	write(1, "\n", 1);
	return 0;
}