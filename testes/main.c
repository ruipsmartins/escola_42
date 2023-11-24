/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:58:27 by rui               #+#    #+#             */
/*   Updated: 2023/11/24 10:58:36 by rui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

void    ft_clean_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10 && buffer[i] != '\n')
		buffer[i++] = 0;
	if (buffer[i] == '\n')
	{
		buffer[i++] = 0;
		while (i < 10 + 1)
		{
			buffer[j] = buffer[i];
			buffer[i] = 0;
			i++;
			j++;
		}
	}
}
int main (){

static char	buffer[11] = "12\n3456";
int         fd;

	fd = open("file1.txt", O_RDONLY);
	read(fd, buffer, 1);
	ft_clean_buffer(buffer);
	read(fd, buffer, 1);

	printf("buffer = %s\n", buffer);
  return (0);
}
