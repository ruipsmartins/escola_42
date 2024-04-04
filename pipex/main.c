#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main (int argc, char *argv[])
{
	int fd [2];

	if (pipe(fd) == -1)
		return 404;
	
	int pid = fork();
	

}