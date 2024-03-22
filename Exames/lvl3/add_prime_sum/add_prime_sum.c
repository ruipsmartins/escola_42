
#include <unistd.h>

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

int main (void)
{
	int number = 7;

	if (is_prime(number))
		write(1, "s\n", 2);
	return 0;
}