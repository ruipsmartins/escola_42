#include <unistd.h>

int main (int ac, char **av)
{
	int count = 0;
	int i = 0;
	int l = 0;

	if (ac == 2 && av[1][0])
	{
		while(av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				count = av[1][i] - 'a';
				while (l <= count)
				{
					write(1, &av[1][i], 1);
					l++;
				}
				l=0;
			}
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				count = av[1][i] - 'A';
				while (l <= count)
				{
					write(1, &av[1][i], 1);
					l++;
				}
				l=0;
			}
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

//cc -Wall -Wextra -Werror repeat_alpha.c -o repeat_alpha