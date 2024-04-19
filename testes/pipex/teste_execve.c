#include <stdio.h>
#include <unistd.h>

int main() {
    char *argv[] = { "ls", "-l", NULL };
    char *envp[] = { NULL }; // Lista de variáveis de ambiente, neste caso vazia

    // Executa o comando ls -l
    execve("/bin/sh", (char *[]){ "sh", "-c", argv[2], NULL }, NULL);

    // Se execve retornar, significa que algo deu errado
    perror("execve erro");
    return 1;
}