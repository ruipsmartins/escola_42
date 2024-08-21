/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 00:04:29 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/05 12:54:19 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static bool	check_unquote(int argc, char **argv)
{
	unsigned int	c;
	unsigned int	i;

	c = 1;
	while (c < (unsigned int)argc)
	{
		i = 0;
		if (argv[c][i] == '-')
		{
			i++;
			if (argv[c][i] == '0')
				return (false);
		}
		while (ft_isdigit(argv[c][i]))
			i++;
		if (argv[c][i])
			return (false);
		c++;
	}
	return (true);
}

static bool	check_quote(char **argv)
{
	unsigned int	i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '-')
		{
			if (argv[1][++i] == '0')
				return (false);
		}
		while (ft_isdigit(argv[1][i]))
			i++;
		if (argv[1][i] == ' ')
			i++;
		else
			break ;
	}
	if (argv[1][i])
		return (false);
	return (true);
}

static bool	check_quote_int(char **argv)
{
	bool			result;
	char			**splits;
	unsigned int	i;

	result = true;
	splits = ft_split(argv[1], ' ');
	i = 0;
	while (result && splits[i])
	{
		result = int_check(ft_atol(splits[i]));
		free(splits[i++]);
	}
	free(splits);
	return (result);
}

bool	argv_check(int argc, char **argv)
{
	unsigned int	i;
	bool			result;

	i = 1;
	result = false;
	if (argc == 2)
	{
		result = check_quote(argv);
		if (result)
			result = check_quote_int(argv);
	}
	else if (argc > 2)
	{
		result = check_unquote(argc, argv);
		if (result)
			while ((unsigned int)argc > i && result)
				result = int_check(ft_atol(argv[i++]));
	}
	return (result);
}
