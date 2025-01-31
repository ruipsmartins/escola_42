#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*

./microshell  cd /home/ruidos-s/ ";" /bin/ls ; /bin/pwd

cc microshell.c -o microshell -Wall -Wextra -Werror

ver do porque de estar a dar mais um \n

 */

void	print_error(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	cd_command(char **argv, int i)
{
	if (i != 2)
		return (print_error("error: cd: bad arguments\n"), 1);
	if (chdir(argv[1]) == -1)
	{
		print_error("error: cd: cannot change directory to ");
		print_error(argv[1]);
		print_error("\n");
		return (1);
	}
	return (0);
}

void	set_pipe(int has_pipe, int *fd, int end)
{
	if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
	{
		print_error("error: fatal\n");
		exit(1);
	}
}

int	execute(char **argv, char **envp, int i)
{
	int		has_pipe;
	int		fd[2];
	pid_t	pid;
	int		status;
	
	(void)fd;
	
	has_pipe = argv[i] && !strcmp(argv[i], "|");

	if (!has_pipe && !strcmp(*argv, "cd"))
		return (cd_command(argv, i));

	if (has_pipe && pipe(fd) == -1)
	{
		print_error("error: fatal\n");
		exit(1);
	}

	if ((pid = fork()) == -1)
	{
		print_error("fork error\n");
		return (1);
	}

	if (pid == 0)
	{
		argv[i] = 0;
		set_pipe(has_pipe, fd, 1);
		execve(*argv, argv, envp);
		print_error("error: cannot execute "), print_error(*argv),
			print_error("\n"), exit(1);
	}
	
	waitpid(0, &status, 0);
	set_pipe(has_pipe, fd, 0);
	return (WIFEXITED(status) && WEXITSTATUS(status));
}



int	main(int argc, char **argv, char **envp)
{
	int	status;
	int	i;

	status = 0;
	i = 0;
	if (argc < 2)
	{
		print_error("error: no arguments\n");
		return (1);
	}
	while (argv[i])
	{
		argv += i + 1;
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (i)
			status = execute(argv, envp, i);
		printf("exit status: %d\n", status);
	}
	printf("exit status: %d\n", status);
	return (status);
}
