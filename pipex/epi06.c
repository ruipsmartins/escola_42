#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

//Communicating between processes (using pipes) in C

int wait();

int main (int argc, char *argv[])
{
	int fd[2];

	if(pipe(fd) == -1)
	{
		printf("error opening the pipe\n");
		return 1;
	}
	int id = fork();

	if (id == 0)
	{
		close(fd[0]);
		int x;
		printf("input a number: ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	} else {
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		close (fd[0]);
		printf("got from child process %d\n", y);
	}
	int a = 65;	
	
	return 0;	
}
