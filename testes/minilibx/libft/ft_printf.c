/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:36:27 by ruidos-s          #+#    #+#             */
/*   Updated: 2024/01/30 12:34:56 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && !*(format + 1))
		{
			return (-1);
			va_end(ap);
		}
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
/* #include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int		count1;
	int		count2;
	char	c;
	char	str[] = "hello";
	int		num;

	c = 'A';
	num = -42;
	count1 = 0;
	count2 = 0;
	 count1 = printf("teu_printf --> %%c=%c s=%s, u=%u, x=%x X=%X p=%p\n", c,
			str, num, num, num, &num);
	count2 = ft_printf("meu_printf --> %%c=%c s=%s, u=%u, x=%x X=%X p=%p\n", c, str,
			num, num, num, &num);

	//count2 = ft_printf(NULL);
	//count1 = printf(NULL);

	printf("\ncount1 = %d, count2 = %d\n", count1, count2);

	return (0);
}
 */