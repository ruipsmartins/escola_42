


int	ft_atoi(const char *str)
{
	int res = 0;
	int i = 0;
	int sign = 1;

	while(str[i] == ' ' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;		
	}
	while (str[i] >= '0' && str[i] <=  '9')
	{
		res =  res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}