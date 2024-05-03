#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int file;
	int stdout_copy;
	if (ac == 2)
	{
		file = open("file_dup2.txt", O_WRONLY | O_CREAT, 0777);
		stdout_copy = dup(STDOUT_FILENO); // Guarda o descritor de ficheiro original
		dup2(file, STDOUT_FILENO); // Redireciona a saída padrão para o ficheiro
		printf("%s", av[1]);
		fflush(stdout);
		dup2(stdout_copy, STDOUT_FILENO); // Restaura a saída padrão para a consola
		close(file);
		printf("programa acabado!\n"); // Escreve "programa acabado!" na consola
	}
	
	return 0;	
}