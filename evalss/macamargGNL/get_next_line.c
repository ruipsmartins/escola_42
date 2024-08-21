/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:39:11 by macamarg          #+#    #+#             */
/*   Updated: 2024/06/05 11:34:53 by ruidos-s         ###   ########.fr       */
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

#include "get_next_line.h"

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
	static char		read_content[BUFFER_SIZE + 1];
	char			*current_line;
	int				read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current_line = NULL;
	while (ft_is_newline(current_line) == -1)
	{
		if (read_content[0] == '\0')
		{
			read_bytes = read(fd, read_content, BUFFER_SIZE);
			if (read_bytes == 0)
				return (current_line);
			else if (read_bytes < 0)
			{
				if (current_line)
					free(current_line);
				return (NULL);
			}
		}
		current_line = ft_strjoin(current_line, read_content);
		ft_clean (current_line, read_content);
	}
	return (current_line);
}
int main()
{
	int	fd;
	char *line;
	int line_count = 0;
	

	fd = open("file1.txt", O_RDONLY | O_CREAT);
	//fd = 0;
	if (fd < 0)
	{
    perror("Error opening file");
    return (EXIT_FAILURE);
    }

    // Read lines until NULL is returned (end of file or error)
    while ((line = get_next_line(fd)) != NULL) 
	{
        // Output the line with a counter 
		printf("Line %d: %s\n", ++line_count, line); 
		free(line); // Free the line once used
	}
	

    // Close the file descriptor
    close(fd);

	return (EXIT_SUCCESS);
}