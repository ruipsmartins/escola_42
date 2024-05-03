#include <stdio.h>
#include <pthread.h>

typedef struct s_cowboy
{
	char		*name;
	pthread_t	thread;
}				t_cowboy;

void	*action(void *data)
{
	t_cowboy cowboy;

	cowboy = *(t_cowboy *)data;
	
	return NULL;
}


int main()
{
	t_cowboy	ugly = {"ugly"};
	t_cowboy	bad = {"bad"};

	pthread_create(&ugly.thread, NULL, action, &ugly);
	pthread_create(&bad.thread, NULL, action, &bad);

	pthread_join(ugly.thread, NULL);
	pthread_join(bad.thread, NULL);

	return 0;
}