#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

char *grab_first(char * str)
{
	int i = 0;
	int len = 0;
	int first_letter;
	char *first_word;
	int j = 0;
	int flag = 1;

	while (str[i] && flag)
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		first_letter = i;
		while (str[i] != ' ' && str[i] != '\t' && str[i])
		{
			i++;
			len ++;
		}	
		first_word = malloc(len + 1);
		while (j < len)
		{
			first_word[j]= str[first_letter];
			first_letter ++;
			j++;
		}
		first_word[j]='\0';	
		flag = 0;
	}
	return (first_word);
}

int main (int ac, char **av)
{
	int i = 0;
	int j = 0;
	char *first_word;
	if (ac > 1)
	{
		first_word = grab_first(av[1]);
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i] == first_word[j] && av[1][i])
		{
			i++;
			j++;
		}
		while(av[1][i])
		{
			while (av[1][i] == ' ' || av[1][i] == '\t')
				i++;
			while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i])
			{
				ft_putchar(av[1][i++]);
				if (av[1][i] == ' ' || av[1][i] == '\t' || !av[1][i])
				{
					ft_putchar(' ');
				}
			}
			
			
		}

		ft_putstr(first_word);
		free(first_word);
	}
	write(1 , "\n", 1);
	return 0;
}