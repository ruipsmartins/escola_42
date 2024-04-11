
#include <stdlib.h>
#include <stdio.h>


int ft_count_words(char *str)
{
	int count = 0;
	int  i = 0;

	while(str[i])
	{
		while (str[i]  && (str[i]=='\t' || str[i]=='\n' || str[i]== ' '))
			i++;
		if (str[i]  && (str[i]!='\t' && str[i]!='\n' && str[i]!= ' '))
			count++;
		while (str[i]  && (str[i]!='\t' && str[i]!='\n' && str[i]!= ' '))
		{
			i++;
		}
	}
	return count;
}


char    **ft_split(char *str)
{
	char **splitted;
	int count_words = ft_count_words(str);
	int i = 0;
	int j = 0;
	int inicio = 0;
	int x = 0;
	int fim = 0;

	splitted = malloc(sizeof(char *) * (count_words + 1));
	if (!splitted)
		return (NULL);	
	while(str[i])
	{
		while (str[i]  && (str[i]=='\t' || str[i]=='\n' || str[i]== ' '))
			i++;
		if (str[i]  && (str[i]!='\t' && str[i]!='\n' && str[i]!= ' '))
			{
			inicio = i;
			fim=i;
			}
		while (str[i] && (str[i]!='\t' && str[i]!='\n' && str[i]!= ' '))
		{
			fim++;
			i++;
		}
		if (str[i] || (str[i-1]!='\t' && str[i-1]!='\n' && str[i-1]!= ' '))
		{
			
			splitted[j] = malloc(sizeof(char) * (fim - inicio + 1));
			x = 0;
			while (inicio < fim)
			{
				splitted[j][x] = str[inicio];
				inicio++;
				x++;
			}
			splitted[j][x] = '\0';
			j++;
		}
		
	}
	splitted[j] = NULL;
	return splitted;
}

/* #include <stdio.h>

int	main(void)
{
	char	*str = "  starting and ending   x";
	int	i;
	char	**box;

	box = ft_split(str);
	i = 0;
	while (box[i])
	{
		printf("%d --> %s\n", i, box[i]);
		free(box[i]);
		i++;
	}
	free(box[i]);
	free(box); 
	return (0);
} */