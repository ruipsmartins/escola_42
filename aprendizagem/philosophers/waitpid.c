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

	int pid1_res = waitpid(pid1, NULL, 0);
	printf("waited for %d \n", pid1_res);	
	int pid2_res = waitpid(pid2, NULL, 0);
	printf("waited for %d \n", pid2_res);	
	

	return 0;
}