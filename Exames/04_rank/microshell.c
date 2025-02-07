#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include <sys/wait.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}

int		print_error(char *str1, char *str2)
{
	if(str1)
		write(2, str1, ft_strlen(str1));
	if(str2)
		write(2, str2, ft_strlen(str2));
	write(2, "\n", 1);
	return (1);
}

void set_pipes(int has_pipe, int *fd, int end)
{
	if(has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		exit(print_error("error: fatal", 0));
}

int cd_command(char **argv, int i)
{
	if (i != 2)
		return print_error("error: cd: bad arguments", 0);
	if(chdir(argv[1]) == -1)
		print_error("error: cd: cannot change directory to ", argv[1]);
	return (0);
}

int		execute(char **argv, int i, char **envp)
{
	int status = 0;
	int pid;
	int has_pipe;
	int fd[2];

	has_pipe = argv[i] && !strcmp(argv[i], "|");

	if(!has_pipe && !strcmp(*argv, "cd"))
		return(cd_command(argv, i));

	if(has_pipe && pipe(fd) == -1)
		exit(print_error("error: fatal pipe", 0));

	if ((pid=fork()) == -1)
		exit(print_error("error: fatal", 0));
	if(pid == 0)
	{
		argv[i] = 0;
		set_pipes(has_pipe, fd, 1);
		execve(*argv, argv, envp);
		exit(print_error("error: cannot execute ", *argv));
	}
	waitpid(0, &status, 0);
	set_pipes(has_pipe, fd, 0);

	return(WIFEXITED(status) && WEXITSTATUS(status));
}

int main (int argc, char **argv, char **envp)
{
	int status=0;
	int i = 0;

	if(argc < 2)
		return (print_error("invalid number of arguments", 0));
	while(argv[i])
	{
		argv += i + 1;
		i = 0;
		while(argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (i)
		{
			status = execute(argv, i, envp);
		}
	}
	return status;
}