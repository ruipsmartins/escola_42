#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
int	i = 0;
int j = 0;
int k = 0;
int checker=0;

	if (ac == 3)
	{
		while (av[1][i])
			i++;
		while (av[2][j])
		{
			av[1][i] = av[2][j];
			j++;
			i++;
		}
		//av[2][j-1] = '\0';
		//printf("%s\n", av[1]);
		i = 0;
		while (av[1][i])
		{
			while (k < i)
			{
				if (av[1][k] == av[1][i])
					checker = 1;
				k++;
			}
			k = 0;
			if (checker == 0)
				write(1, &av[1][i], 1);
			i++;
			checker = 0;
		}
	}
	write(1, "\n", 1);
	return 0;
}
//cc -Wall -Wextra -Werror union.c -o union