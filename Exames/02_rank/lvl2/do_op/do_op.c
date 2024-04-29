/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:03:12 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/03/18 17:14:10 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int main (int argc, char **argv)
{
	if (argc==4)
	{
		int res = 0;
		if (argv[2][0] == '+')
		{
			res = atoi(argv[1]) + atoi(argv[3]);
		}
		if (argv[2][0] == '-')
		{
			res = atoi(argv[1]) - atoi(argv[3]);
		}
		if (argv[2][0] == '*')
		{
			res = atoi(argv[1]) * atoi(argv[3]);
		}
		if (argv[2][0] == '/')
		{
			res = atoi(argv[1]) / atoi(argv[3]);
		}
		
	printf("%d", res);
	}
	printf("\n");
}