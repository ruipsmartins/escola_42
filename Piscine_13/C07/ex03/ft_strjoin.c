/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:42:54 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/08/16 13:53:34 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcat(int size, char **strs, char *sep, char *result)
{
	int	t;
	int	i;
	int	j;

	i = 0;
	t = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			result[t++] = strs[i][j++];
		}
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
			{
				result[t++] = sep[j++];
			}
		}
		i++;
	}
	result[t] = '\0';
}

int	ft_calculate_total(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			total_len += ft_strlen(sep);
		}
		i++;
	}
	total_len++;
	return (total_len); 
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	char	*empty_string;
	char	*result;

	if (size <= 0)
	{
		empty_string = (char *)malloc(1);
		if (empty_string != NULL)
		{
			empty_string[0] = '\0';
		}
		return (empty_string);
	}
	total_len = ft_calculate_total(size, strs, sep);
	result = (char *)malloc(total_len);
	if (result != NULL)
	{
		ft_strcat(size, strs, sep, result);
	}
	return (result);
}
/*
#include <stdio.h>

int main(int argc, char **argv) {
    char sep[] = "-";
    char *result = ft_strjoin(argc - 1, argv + 1, sep);
    if (result != NULL) {
        printf("%s\n", (result));
        free(result);
    } 
    return 0;
}*/
