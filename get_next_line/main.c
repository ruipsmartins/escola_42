/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:16:18 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/17 16:29:15 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("example.txt", O_RDONLY);
	while (++i)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		printf("|%d: %s", i, line);
		free(line);
	}
	//printf("......nada.aqui......\n");
	return (0);
}
