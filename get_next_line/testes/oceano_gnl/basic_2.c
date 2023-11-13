/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:38:02 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/13 12:05:48 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	buf[256];
	int		chars_read;

	fd = open("file.txt", O_RDONLY);

	while ((chars_read = read(fd, buf, 25)))
	{
		buf[chars_read] = '\0';
		printf("buf -> %s\n", buf);
	}

	return (0);
}
