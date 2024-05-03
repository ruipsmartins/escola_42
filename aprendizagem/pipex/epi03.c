#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int wait();

int main (int argc, char *argv[])
{
	int id = fork();
	int n;
	
	if (id == 0)
	{
		n = 1;
	} else
	{
		n = 6;
		wait(NULL);
	}
	

	int i = n;
	while (i < n + 5)
	{
		printf("%d ", i);
		i++;
	} 
	
	if (id)
	{
		printf("\n");
	}
	return 0;	
}