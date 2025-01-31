#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int	print_error(char *str1, char *str2, char *str3)
{
	int	i;

	i = 0;
	while (str1 && str1[i])
		write(2, &str1[i++], 1);
	i = 0;
	while (str2 && str2[i])
		write(2, &str2[i++], 1);
	i = 0;
	while (str3 && str3[i])
		write(2, &str3[i++], 1);
	return (1);
}
int	cd_command(char **argv, int i)
{
	if (i != 2)
		return (print_error("error: cd: bad arguments", "\n", 0));
	if (chdir(argv[1]) == -1)
		return (print_error("error: cd: cannot change directory to ", *argv,
				"\n"));
	return (0);
}

void	set_pipes(int has_pipe, int *fd, int end)
{
	if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1
			|| close(fd[1]) == -1))
		exit(print_error("error: fatal\n", NULL, NULL));
}

int	execute(char **argv, int i, char **envp)
{
	int	status;
	int	pid;
	int	has_pipe;
	int	fd[2];

	status = 0;
	has_pipe = argv[i] && !strcmp(argv[i], "|");
	if (!has_pipe && !strcmp(*argv, "cd"))
		return (cd_command(argv, i));
	if (has_pipe && (pipe(fd)) == -1)
		exit(print_error("error: fatal\n", NULL, NULL));
	if ((pid = fork()) == -1)
		exit(print_error("error: fatal\n", NULL, NULL));
	if (!pid)
	{
		argv[i] = 0;
		set_pipes(has_pipe, fd, 1);
		execve(*argv, argv, envp);
		exit(print_error("error: cannot execute ", *argv, "\n"));
	}
	set_pipes(has_pipe, fd, 0);
	waitpid(0, &status, 0);
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	int	status;
	int	i;

	status = 0;
	i = 0;
	(void)envp;
	if (argc < 2)
		return (print_error("need more args", NULL, "\n"));
	while (argv[i])
	{
		argv += i + 1;
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (i)
			execute(argv, i, envp);
	}
	return (status);
}
