/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:22:40 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/14 10:37:00 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(int nb)
{
	int			i;
	long int	nbr;

	nbr = (long)nb;
	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str_nbr;
	size_t		size_str;
	long int	nbr;

	nbr = (long) n;
	size_str = ft_size(nbr);
	str_nbr = (char *)malloc(size_str + 1);
	if (!str_nbr)
		return (NULL);
	str_nbr[size_str] = '\0';
	if (nbr == 0)
		*str_nbr = '0';
	if (nbr < 0)
	{
		*str_nbr = ('-');
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str_nbr[size_str - 1] = (nbr % 10) + '0';
		nbr /= 10;
		size_str--;
	}
	return (str_nbr);
}
//line 48 - place a NULL termminator in the string
//line 58 - starts from the end of the string, the units
//line 59 - removes the last digit
