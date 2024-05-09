#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int pid1 = fork();
	if (pid1 == -1)
	{
		printf("error creating pid 1\n");
		return 1;
	}

	if (pid1 == 0)
	{
		sleep(4);
		printf("finished execution (%d)\n", getpid());
		return 0;
	}
	

	int pid2 = fork();
	if (pid2 == -1)
	{
		printf("error creating pid 2\n");
		return 1;
	}

	if (pid2 == 0)
	{
		sleep(1);
		printf("finished execution (%d)\n", getpid());
		return 0;
	}

	wait(NULL);	
	wait(NULL);

	return 0;
}