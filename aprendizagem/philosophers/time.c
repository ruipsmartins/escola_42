#include <stdio.h>
#include <sys/time.h>
#include <stdint.h>
#include <unistd.h>

//int gettimeofday(struct timeval *tv, struct timezone *tz);



void example_1()
{
	struct timeval time;
	
	if(gettimeofday(&time, NULL))
		return ;

	printf("%ld seconds\n", time.tv_sec);
	printf("%ld microseconds\n", time.tv_usec);

	printf("%ld years passed since 1970\n\n", time.tv_sec / 60 / 60 / 24 / 365);
	
}

uint64_t get_time(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		return(0);

	return((tv.tv_sec * (uint64_t)1000) + (tv.tv_sec / 1000));
}


void example_2()
{
	uint64_t start_time;
	uint64_t now;

	start_time = get_time();
	usleep(100000);
	now = get_time();
	printf("%ld milliseconds passed since the start\n", now - start_time);
}

int main (void)
{
	//example_1();
	example_2();

	return 0;
}