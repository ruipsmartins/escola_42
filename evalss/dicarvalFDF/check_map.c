/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:36:46 by dicarval          #+#    #+#             */
/*   Updated: 2024/09/09 15:03:31 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	strcmp_fdf(char *map_name)
{
	int		i;
	int		j;
	char	*fdf;

	fdf = ".fdf";
	i = 0;
	j = 0;
	while (map_name[i] != '\0')
		i++;
	i -= 4;
	while (map_name[i] != '\0')
	{
		if (map_name[i++] != fdf[j++])
			return (0);
	}
	return (1);
}

static void	check_empty_map(t_data *data, char *line)
{
	if (line == NULL)
	{
		perror("The map file is empty\n");
		ft_close_fdf(data);
	}
}

static int	digit_check(t_data *data, char *line)
{
	char	**temp;
	int		i;
	int		line_len;

	if (!line)
		return (0);
	temp = ft_split(line, ' ');
	line_len = 0;
	while (temp[line_len])
	{
		i = 0;
		while (temp[line_len][i] && temp[line_len][i] != '\n')
		{
			if (temp[line_len][i] == ',')
				break ;
			if (temp[line_len][i] == '-' && i == 0)
				i++;
			if (!ft_isdigit(temp[line_len][i]))
				free_split(temp, 1, data);
			i++;
		}
		line_len++;
	}
	free_split(temp, 2, data);
	return (line_len);
}

static int	check_digits_map(int fd, t_data *data)
{
	char	*line;
	int		line_len;
	int		line_len2;

	line = get_next_line(fd);
	check_empty_map(data, line);
	line_len = digit_check(data, line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			line_len2 = digit_check(data, line);
		if (line_len != line_len2)
		{
			free(line);
			perror("The map isn't a square or a rectangule\n");
			exit(0);
		}
	}
	free(line);
	data->width = line_len;
	return (1);
}

int	check_map(t_data *data)
{
	int	fd;

	if (!strcmp_fdf(data->map_file[data->map_num]))
	{
		perror("The file is not a .fdf file\n");
		ft_close_fdf(data);
	}
	else
	{
		fd = open(data->map_file[data->map_num], O_RDONLY);
		if (fd == -1)
		{
			perror("No file in the directory or it has no permissions\n");
			ft_close_fdf(data);
		}
		else if (check_digits_map(fd, data))
		{
			close(fd);
			fd = open(data->map_file[data->map_num], O_RDONLY);
		}
		return (fd);
	}
	return (0);
}
