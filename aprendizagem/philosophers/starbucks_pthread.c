#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *make_coffee(void *data)
{
	printf("Barista preparing coffee \n");
	sleep(2);
	printf("coffee ready!\n");
	sleep(10);
	return NULL;
}

int main()
{
	pthread_t	baristas[50];


	for (size_t i = 0; i < 50; i++)
	{
	pthread_create(baristas + i, NULL, make_coffee, NULL);
	printf("Identifier -> %lu\n",baristas[i]);
	}

	for (size_t i = 0; i < 50; i++)
	{
		pthread_join(baristas[i],NULL);
	}
	
	return 0;
}