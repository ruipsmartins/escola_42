/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:11:37 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/04/01 17:25:48 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int flag = 0;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			while (argv[1][i] == ' ' || argv[1][i]== '\t')
				i++;
			if (argv[1][i] && flag)
			{
				write(1," ", 1);
				flag = 0;
			}
			while ((argv[1][i] != ' ' && argv[1][i] != '\t') && argv[1][i])
			{
				write(1, &argv[1][i], 1);
				flag = 1;
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return 0;
}