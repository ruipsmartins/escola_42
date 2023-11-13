/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:03:00 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/11/13 11:35:52 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDWR | O_CREAT | O_APPEND, 0640);
	dup2(fd, 1);
	printf("Tamanho de um char: %lu\n", sizeof(char));
	printf("Tamanho de um int: %lu\n", sizeof(int));
	write(fd, "hello ", 6);
	return (0);
}
