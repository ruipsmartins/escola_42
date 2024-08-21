/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:39:11 by macamarg          #+#    #+#             */
/*   Updated: 2024/06/05 11:39:19 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Write a function that returns a line read from a
file descriptor
If successful, get_next_line returns a string with the full line ending in
a line break (`\n`) when there is one.
If an error occurs, or there's nothing more to read, it returns NULL.

Takes the opened file descriptor and saves on a "buff" variable what readed
from it. Then joins it to the cumulative static variable for the persistence
of the information.
*	PARAMETERS
#1. A file descriptor.
#2. The pointer to the cumulative static variable from previous runs of
get_next_line.
*   RETURN VALUES
The new static variable value with buffer joined for the persistence of the info,
or NULL if error.

#include <unistd.h>

       ssize_t read(int fd, void buf[.count], size_t count);

*/

#include "get_next_line_bonus.h"

void	*ft_clean(char *current_line, char *read_content)
{
	int	pos;
	int	i;

	pos = ft_is_newline(current_line);
	if (pos != -1)
		current_line[pos + 1] = '\0';
	i = 0;
	pos = ft_is_newline(read_content);
	if (pos != -1)
	{
		pos++;
		while (read_content[pos + i] != '\0')
		{
			read_content[i] = read_content[pos + i];
			i++;
		}
	}
	while (read_content[i] != '\0')
	{
		read_content[i] = '\0';
		i++;
	}
	return (current_line);
}

char	*get_next_line(int fd)
{
	static char		read_content[FOPEN_MAX][BUFFER_SIZE + 1];
	char			*current_line;
	int				read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	current_line = NULL;
	while (ft_is_newline(current_line) == -1)
	{
		if (read_content[fd][0] == '\0')
		{
			read_bytes = read(fd, read_content[fd], BUFFER_SIZE);
			if (read_bytes == 0)
				return (current_line);
			else if (read_bytes < 0)
			{
				if (current_line)
					free(current_line);
				return (NULL);
			}
		}
		current_line = ft_strjoin(current_line, read_content[fd]);
		ft_clean (current_line, read_content[fd]);
	}
	return (current_line);
}

int main()
{
	int	fd[3];
	char *line[3];
	int	line_count[3];
	
	fd[0] = open("file1.txt", O_RDONLY | O_CREAT);
	fd[1] = open("file2.txt", O_RDONLY | O_CREAT);
	fd[2] = open("file3.txt", O_RDONLY | O_CREAT);
	if (fd[0] < 0 || fd[1] < 0 || fd[2] < 0)
	{
    perror("Error opening file");
    return (EXIT_FAILURE);
    }
	line_count[0] = 0;
	line_count[1] = 0;
	line_count[2] = 0;
    if((line[0] = get_next_line(fd[0])) != NULL && 
	(line[1] = get_next_line(fd[1])) != NULL 
	&& (line[2] = get_next_line(fd[2])) != NULL) 
	{
        // Output the line with a counter 
		printf("Line1 %d: %s\n", ++line_count[0], line[0]);
		printf("Line2 %d: %s\n", ++line_count[1], line[1]);
		printf("Line3 %d: %s\n", ++line_count[2], line[2]);
		free(line[0]); // Free the line once used
		free(line[1]);
		free(line[2]);
		
	}

	if((line[0] = get_next_line(fd[0])) != NULL && 
	(line[1] = get_next_line(fd[1])) != NULL 
	&& (line[2] = get_next_line(fd[2])) != NULL) 
	{
        // Output the line with a counter 
		printf("Line1 %d: %s\n", ++line_count[0], line[0]);
		printf("Line2 %d: %s\n", ++line_count[1], line[1]);
		printf("Line3 %d: %s\n", ++line_count[2], line[2]);
		free(line[0]); // Free the line once used
		free(line[1]);
		free(line[2]);
		
	}
	
    // Close the file descriptor
    close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	return (EXIT_SUCCESS);
}