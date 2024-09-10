/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:54:23 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/26 17:35:55 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	prep_next_line(t_gnl **lnklist)
{
	t_gnl	*last;
	t_gnl	*char_n_used;
	int		i;
	int		k;

	if (lnklist == NULL)
		return ;
	char_n_used = malloc(sizeof(t_gnl));
	char_n_used->buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	char_n_used->next = NULL;
	if (char_n_used->buf == NULL)
		return ;
	i = 0;
	k = 0;
	last = lstlast(*lnklist);
	while (last->buf[i] != '\n' && last->buf[i] != '\0')
		i++;
	if (last->buf[i] == '\n')
		i++;
	while (last->buf[i] != '\0')
		char_n_used->buf[k++] = last->buf[i++];
	char_n_used->buf[k] = '\0';
	free_content(lnklist, char_n_used);
}

char	*cpy_line(t_gnl *lnklist)
{
	int		i;
	int		j;
	char	*new_line;
	size_t	line_len;

	if (lnklist == NULL)
		return (NULL);
	line_len = list_len(lnklist);
	new_line = malloc(sizeof(char) * line_len + 1);
	if (new_line == NULL)
		return (NULL);
	j = 0;
	while (lnklist != NULL)
	{
		i = 0;
		while (lnklist->buf[i] != '\0' && lnklist->buf[i] != '\n')
			new_line[j++] = lnklist->buf[i++];
		if (lnklist->buf[i] == '\n')
			new_line[j++] = lnklist->buf[i];
		lnklist = lnklist->next;
	}
	new_line[j] = '\0';
	return (new_line);
}

void	create_list(t_gnl **lnklist, int fd)
{
	int		i;
	t_gnl	*node;

	while (end_line(*lnklist) == 0)
	{
		node = malloc(sizeof(t_gnl));
		node->buf = malloc(BUFFER_SIZE + 1);
		node->next = NULL;
		if (node->buf == NULL)
			return ;
		i = read(fd, node->buf, BUFFER_SIZE);
		if (i <= 0)
		{
			free(node->buf);
			free(node);
			return ;
		}
		node->buf[i] = '\0';
		lstadd_back(lnklist, node);
	}
}

char	*get_next_line(int fd)
{
	static t_gnl	*lnklist = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&lnklist, fd);
	if (lnklist == NULL)
		return (NULL);
	line = cpy_line(lnklist);
	if (line == NULL)
		return (NULL);
	prep_next_line (&lnklist);
	return (line);
}
