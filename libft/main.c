/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:16:18 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/30 15:04:16 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;
	int		i;
	int		change_fd;

	i = 0;
	change_fd = 1;
	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	while (++i)
	{
		if (change_fd > 0)
		{
			line = get_next_line(fd1);
			change_fd *= -1;
		}
		else
		{
			line = get_next_line(fd2);
			change_fd *= -1;
		}
		if (!line)
		{
			free(line);
			break ;
		}
		ft_printf("|%d: %s", i, line);
		free(line);
	}
	return (0);
}
