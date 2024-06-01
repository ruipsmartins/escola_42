#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

int ft_putchar(char c)
{
	return(write(1, &c,1));
}

int	ft_putstr(char *str)
{
	int i = 0;
	if (!str)
		return ft_putstr("(null)");
	while (str[i])
		i += ft_putchar(str[i]);
	return i;
}

int ft_putnbr_base(long num, int base)
{
	int		count = 0;
	char	*str = "0123456789abcdef";

	if (num < 0)
	{
		count += ft_putstr("-");
		return count += ft_putnbr_base(-num, base);
	}
	if (num > base)
	{
		count += ft_putnbr_base(num / base, base);
		return count += ft_putnbr_base(num % base, base);
	}
	if (num < base)
	{
		return (count += ft_putchar(str[num]));
	}
	return count;
}
int ft_printf(const char *fmt, ... )
{
	int count  = 0;

	va_list ap;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && (fmt + 1))
		{
			fmt++;
			if (*fmt == 's')
				count += ft_putstr(va_arg(ap, char *));
			else if (*fmt == 'd')
				count += ft_putnbr_base(va_arg(ap, int), 10);
			else if (*fmt == 'x')
				count += ft_putnbr_base(va_arg(ap, unsigned int), 16);
			fmt++;
		}
		else
		{
		count += ft_putchar(*fmt++);
		}
	}
	va_end(ap);
	return count;
}


int main (void)
{
	char	*str="hello world";
	int 	ft_count = 0;
	int		count = 0;
	int		grande = -2147;

	count += printf("str = %s, int = %d, exa = %x.\n", str, grande, grande);

	ft_count += ft_printf("str = %s, int = %d, exa = %x.\n", str, grande, grande);

	printf("\ncount = %d\n", count);
	printf("ft_count = %d\n", ft_count);
	return 0;
}