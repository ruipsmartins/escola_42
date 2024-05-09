#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>

uint64_t ledger = 0;

pthread_mutex_t ledger_lock;

void *update_ledger(void *data)
{
	pthread_mutex_lock(&ledger_lock);
	ledger += 1;
	pthread_mutex_unlock(&ledger_lock);
	return NULL;
}

int main()
{
	pthread_t	baristas[1000];

	pthread_mutex_init(&ledger_lock, NULL);

	for (size_t i = 0; i < 1000; i++)
	{
	if (pthread_create(baristas + i, NULL, update_ledger, NULL))
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < 1000; i++)
	{
		pthread_join(baristas[i],NULL);
	}

	printf("%lu\n", ledger);
	
	return 0;
}