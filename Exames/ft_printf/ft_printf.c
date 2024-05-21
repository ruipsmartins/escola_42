#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

static int	ft_putstr(const char *s)
{
	int len = 0;
	while (s[len])
		len++;
	write(1, s, len);
	return (len);
}

static int	ft_putnbr(int n)
{
	char	c;
	long	nbr;
	int		len = 0;

	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		len++;
		nbr = -nbr;
	}
	if (nbr > 9)
		len += ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
	return (len + 1);
}

static int	ft_puthex(unsigned int n)
{
	char	*hex = "0123456789abcdef";
	int		len = 0;
	
	if (n >= 16)
		len += ft_puthex(n / 16);
	write(1, &hex[n % 16], 1);
	return (len + 1);
}

static int	handle_conversion(const char *format, va_list args)
{
	if (*format == 's')
	{
		char *str = va_arg(args, char *);
		if (str)
			return ft_putstr(str);
		else
			return ft_putstr("(null)");
	}
	else if (*format == 'd')
		return ft_putnbr(va_arg(args, int));
	else if (*format == 'x')
		return ft_puthex(va_arg(args, unsigned int));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count = 0;
	int		tmp;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			tmp = handle_conversion(format, args);
			count += tmp;
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

/* int	main(void)
{
	int written = 0;

	written += ft_printf("%s\n", "toto");
	written += ft_printf("Magic %s is %d\n", "number", 42);
	written += ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	
	ft_printf("written: %d\n", written);
	return (0);
} */
