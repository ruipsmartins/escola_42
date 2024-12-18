
#include"ft_printf.h"
#include<stdio.h>
int main(void)
{
int		count1;
	int		count2;
	char	c;
	char	str[] = "hello";
	int		num;

	c = 'A';
	//num = 214748364;
	count1 = 0;
	count2 = 0;
	 count1 = printf("teu_printf --> %%c=%c s=%s, u=%u, x=%x X=%X p=%p\n", c,
			str, 2147483650, num, num, &num);
	count2 = ft_printf("meu_printf --> %%c=%c s=%s, u=%u, x=%x X=%X p=%p\n", c, str,
			2147483649, num, num, &num);

	/* count2 = ft_printf(NULL);
	count1 = printf(NULL); */

	printf("\ncount1 = %d, count2 = %d\n", count1, count2);

	return (0);
}