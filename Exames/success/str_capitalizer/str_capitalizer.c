
#include <unistd.h>


char to_upper(char c)
{
	if (c >= 'a' && c <='z')
	{
		c = c - 32;
	}
	return c;
}
char to_lower(char c)
{
	if (c >= 'A' && c <='Z')
	{
		c = c + 32;
	}
	return c;
}

void printstr (char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i - 1] == ' ' || str[i - 1] == '\t'  || i == 0)
		{
			str[i] = to_upper(str[i]);
		}
		else
			str[i] = to_lower(str[i]);
		write(1, &str[i], 1);
		i++;
	}
}

int main (int ac, char **av)
{
	int i = 1;

	if (ac > 1)
	{
		while (i < ac)
		{
			printstr(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return 0;
}