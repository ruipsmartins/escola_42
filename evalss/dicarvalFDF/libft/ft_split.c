/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:05:15 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/14 10:37:19 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_string(char c, char spltr)
{
	if (spltr == c)
		return (0);
	return (1);
}

static int	ft_strlen_s(char const *str, char spltr)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && in_string(str[i], spltr))
		i++;
	return (i);
}

static int	count_strings(char const *str, char spltr)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && !in_string(str[i], spltr))
			i++;
		if (str[i] != '\0')
			counter++;
		while (str[i] != '\0' && in_string(str[i], spltr))
			i++;
	}
	return (counter);
}

static char	*word_allocate(char const *str, char spltr)
{
	int		len_word;
	char	*word;
	int		i;

	i = 0;
	len_word = ft_strlen_s(str, spltr);
	word = (char *)malloc((len_word + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	word[len_word] = 0;
	while (str[i] != '\0' && in_string(str[i], spltr))
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}
//line 58 - length of the string
//line 59 - malloc of length of the string

char	**ft_split(char const *str, char spltr)
{
	char	**list_str;
	int		number_str;
	int		g;

	g = 0;
	if (str == NULL)
		return (NULL);
	number_str = count_strings(str, spltr);
	list_str = (char **)malloc((number_str + 1) * sizeof(char *));
	if (list_str == NULL)
		return (NULL);
	list_str[number_str] = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && !in_string(*str, spltr))
			str++;
		if (*str != '\0')
		{
			list_str[g] = word_allocate(str, spltr);
			g++;
		}
		while (*str != '\0' && in_string(*str, spltr))
			str++;
	}
	return (list_str);
}
//line 80 - count the number of strings
//line 81 - malloc the array of strings
//line 87 - moves forward until it finds a non-splitter
//line 91 - allocates the string in the correct order
//line 94 - moves forward until it finds a splitter or the end of the string
