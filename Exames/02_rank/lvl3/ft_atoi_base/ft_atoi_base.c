/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:26:39 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/04/01 19:06:36 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int result  = 0;
	int sign = 1;
	int i = 0;
	
	if (str[i]== '-')
	{
		sign *= -1;
		i++;
	}

	while (str[i])
	{
		int digit = 0;

		if (str[i] >= '0' && str[i] <= '9')
			digit = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			digit = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			digit = str[i] - 'A' + 10;

		result = result * str_base + digit;
		i++;
	}

	return (result * sign);
}



int main (void)
{

	int num = ft_atoi_base("1ab", 16);

	printf("%d\n", num);
	

return 0;
}