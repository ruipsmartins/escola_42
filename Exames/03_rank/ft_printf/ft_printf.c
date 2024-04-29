#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int	printf_putchar(char c)
{
	return (write(1, &c, 1));
}

int	printf_putstr(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		s = ("(null)");
	while (*s)
	{
		printf_putchar(*s++);
		count++;
	}
	return (count);
}

int print_format(char specifier, va_list ap)
{
	int count = 0;

	if (specifier == 'c')
	{
		print_char(va_arg(ap, char));
	}
	


	return count;
}


int ft_printf(const char *format, ... )
{
	int count = 0;
	va_list ap;

	va_start(ap, format);

	while(*format != '\0')
	{
		if (*format == '%')
		{
			count += print_format(*(++format), ap);
		}
		else
			count += printf_putchar(*format);
		format++;
	}


	va_end(ap);
	return count;
}



int main (void)
{
	int count;
	int num = 42;
	char *str= "hello world";

	count = ft_printf("str = %s, num = %d", str, num);
	ft_printf(" i = %d\n", count);
	return (0);
}