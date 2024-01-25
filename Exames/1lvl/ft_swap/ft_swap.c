void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	
}
#include <stdio.h>

int main (void)
{
int a = 5;
int b = 10;

ft_swap(&a, &b);
printf("a %d\n", a);
printf("b %d\n", b);
return 0;
}