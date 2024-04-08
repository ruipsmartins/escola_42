#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int wait();

int main (int argc, char *argv[])
{
	int id1 = fork();
	int id2 = fork();

	while (wait(NULL) != -1 && errno != ECHILD)
	{
		printf("Waited for a child to finish\n");
	}
	if (id1 == 0)
	{
		if (id2 == 0)
		{
			printf("grandchild\n");
		} else {
			printf("1st child\n");
		}
	} else {
		if (id2 == 0)
		{
			printf("2nd child\n");
		} else {
			printf("parent\n");
		}
	}
	
	
	
	return 0;	
}
