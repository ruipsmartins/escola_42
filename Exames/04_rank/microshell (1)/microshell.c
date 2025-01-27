#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

void err(char *str)
{
    // Loop through each character in the string and write it to stderr
    while (*str)
        write(2, str++, 1);
}

int cd_command(char **argv, int i)
{
	if (i != 2)
        return err("error: cd: bad arguments\n"), 1;
	if (chdir(argv[1]) == -1)
	{
		err("error: cd: cannot change directory to ");
		err(argv[1]);
		err("\n");
		return 1;
	}

return 0;
}

int	execute(char **argv, char **envp, int i)
{
	int		has_pipe;
	int		fd[2];
	pid_t	pid;
	int		status;

	if(!strcmp(*argv, "cd"))
			return(cd_command(argv, i));
	if ((pid = fork()) == -1)
	{
		write(2, "fork error\n", 12);
		return 1;
	}
	if (pid == 0)
	{
		argv[i] = 0;
		execve(*argv, argv , envp);
		err("error: cannot execute "), err(*argv), err("\n"), exit(1);	
	}
	else
		waitpid(pid, &status, 0);
	return WIFEXITED(status) && WEXITSTATUS(status);
}


int	main (int argc, char **argv, char **envp)
{
	int status=0;
	int i = 0;

	if (argc < 2)
	{
		printf("Uso: %s <comandos> [; <comandos> ...]\n", argv[0]);
		return (1);
	}

	while(argv[i])
	{
    	argv += i + 1;
    	i = 0;
		while(argv[i] && strcmp(argv[i], ";"))
			i++;
		if (i)
			status = execute(argv, envp, i);
	}

	printf("exit status: %d\n", status);
	return (status);
}
