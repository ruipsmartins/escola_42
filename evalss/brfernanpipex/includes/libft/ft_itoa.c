/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:00:21 by brfernan          #+#    #+#             */
/*   Updated: 2024/04/01 23:55:50 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_number_size(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_number_size(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (n)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}
