/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:05:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/18 15:27:24 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <ctype.h>


int	main(void)
{
	char	*str = "hello world    teste";
	char	c = ' ';
	int	i;
	char	**box;


	box = ft_split(str, c);
	i = 0;
	while (box[i])
	{
		printf("%d --> %s\n", i, box[i]);
		free(box[i]);
		i++;
	}
	free(box[i]);
	free(box); 
	return (0);
}
