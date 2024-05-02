#include <stdio.h>
#include <pthread.h>

typedef struct s_cowboy
{
	char		*name;
	pthread_t	thread;
}				t_cowboy;


int main()
{
	t_cowboy	ugly = {"ugly"};
	t_cowboy	bad = {"bad"};



	return 0;
}