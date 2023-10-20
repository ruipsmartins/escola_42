/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:23:34 by ruidos-s          #+#    #+#             */
/*   Updated: 2023/10/20 12:55:54 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled. */

#include "libft.h"

static	int	count_num(long lnum)
{
	int	count;

	count = 0;
	if (lnum <= 0)
		count ++;
	while (lnum)
	{
		lnum = lnum / 10;
		count ++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str_num;
	int		i;
	long	lnum;

	lnum = n;
	i = count_num(lnum);
	str_num = (char *)malloc(i * sizeof(char) + 1);
	if (!str_num)
		return (NULL);
	str_num[i--] = '\0';
	if (lnum == 0)
		str_num[0] = '0';
	else if (lnum < 0)
	{
		str_num[0] = '-';
		lnum *= -1;
	}
	while (lnum)
	{
		str_num[i] = lnum % 10 + 48;
		lnum /= 10;
		i--;
	}
	return (str_num);
}
/* int	main(void)
{
	int	num;

	num = -12345;
	printf("ft_itoa: %s\n", ft_itoa(num));
	return (0);
}
 */