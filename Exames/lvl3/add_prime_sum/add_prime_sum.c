
#include <unistd.h>
#include <stdio.h>

int is_prime(int number)
{
	int i = 2;
	while (i <= number / 2)
	{
		if (number % i == 0)
			return 0;
		i++;
	}
	return 1;
}
int ft_atoi(char *c)
{
	int res = 0;
	int i = 0;

	while (c[i])
	{
		res = (res * 10) + (c[i] - '0');
		i++;
	}
	return res;
}

void ft_putnumber(int num)
{
	char c;
	if (num <= 9)
	{
		c = num  + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnumber(num / 10);
		ft_putnumber(num % 10);
	} 

}

int main (int argc, char **argv)
{
	int num = 0;
	int res = 0;
	int i = 2;

	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		if (num > 0)
		{
			while (i <= num)
			{
				if (is_prime(i))
				{
					res = res + i;
				}
				i++;
			}
		}
	}
		ft_putnumber(res);
		write(1, "\n", 1);
	return 0;
}