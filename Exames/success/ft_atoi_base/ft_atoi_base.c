

int	ft_atoi_base(const char *str, int str_base)
{
	int res = 0;
	int sign = 1;
	int i = 0;

	if (str[i] == '-')
	{
		sign= -1;
		i++;
	}

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res =  res * str_base + str[i] - '0';
		}
		else if (str[i] >= 'a' && str[i] <= 'f')
		{
			res =  res * str_base + str[i] - 'a' + 10;
		}
		else if (str[i] >= 'A' && str[i] <= 'F')
		{
			res =  res * str_base + str[i] - 'A' + 10;
		}
		else
			return (res * sign);

		i++;
	}

	return (res * sign);
}

/* #include <stdio.h>
int main (void)
{
	int num = 0;

	num = ft_atoi_base("Ceci permi", 16);

	printf("num = %d\n", num);


	return 0;
} */