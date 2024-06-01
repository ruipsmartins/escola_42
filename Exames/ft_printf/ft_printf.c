#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
	int count = 0;
	if (str == NULL)
		return ft_putstr("(null)");
	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}

int	ft_putnbr(long number, int base)
{
	char	*symbols = "0123456789abcdef";
	int		count = 0;

	if (number < 0)
	{
		count += ft_putchar('-');
		number = number * -1;
	}
	if (number < base)
	{
		count += ft_putchar(symbols[number % base]);
	}
	else
	{
		count += ft_putnbr(number / base, base);
		count += ft_putnbr(number % base, base);
	}
	return count;
}
static int handle_conversion(const char *format, va_list ap)
{
	if (*format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if(*format == 's')
		return ft_putstr(va_arg(ap, char *));
	else if (*format == 'd')
		return ft_putnbr(va_arg(ap, int), 10);
	else if (*format == 'x')
		return ft_putnbr(va_arg(ap, unsigned int), 16);
	return 0;
}

int ft_printf(char *format, ... )
{
	va_list ap;
	int count = 0;
	int tmp = 0;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			tmp = handle_conversion(format++, ap);
			count += tmp;
		}
		else
		{
			write(1, format++, 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
/* 
int	main(void)
{
	int count = 0;

	ft_printf("%d\n", -21474836488);
	printf("%d\n", -21474836488);
	return (0);
} */