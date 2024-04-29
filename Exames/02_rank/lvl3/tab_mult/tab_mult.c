#include <unistd.h>

int ft_atoi(char *str)
{
	int i = 0;
	int res = 0;

	while (str[i])
	{
		res =  res * 10 + str[i] - '0';
		i++;
	}
	
	return res;
}

void print_number (int number)
{
	if (number <= 9)
	{
		char digit = '0' + number;
		write(1, &digit, 1);
	}
	else
	{
		print_number(number / 10);
		print_number(number % 10);
	}
}

int main (int ac, char **av)
{
	int i=1;

	if (ac == 2)
	{
		int number = ft_atoi(av[1]);
		while (i <= 9)
		{
			print_number(i);
			write(1, " x ", 3);
			print_number(number);
			write(1," = ", 3);
			print_number (i*number);
			write(1, "\n", 1);
			i++;

		}
	}
	
	else
		write(1, "\n", 1);

	return 0;
}