#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int ac, char **av)
{
	int fd[2];
	int pid;
	int file;

	if (ac == 2)
	{
		if (pipe(fd) < 0) {
			perror("pipe");
			exit(1);
		}

		pid = fork();

		if (pid < 0) {
			perror("fork");
			exit(1);
		}

		if (pid == 0) {
			// Filho
			close(fd[0]); // Fecha a extremidade de leitura do tubo
			file = open("file_dup2.txt", O_WRONLY | O_CREAT, 0777);
			dup2(file, STDOUT_FILENO); // Redireciona a saída padrão para o arquivo
			printf("%s", av[1]);
			close(file); // Fecha o arquivo
			close(fd[1]); // Fecha a extremidade de escrita do tubo
			exit(0);
		} else {
			// Pai
			close(fd[1]); // Fecha a extremidade de escrita do tubo
			//dup2(fd[0], STDIN_FILENO); // Redireciona a entrada padrão para o tubo
			close(fd[0]); // Fecha a extremidade de leitura do tubo
			printf("programa acabado!\n"); // Escreve "programa acabado!" na consola
			wait(NULL); // Espera que o filho termine
		}
	}

	return 0;
}