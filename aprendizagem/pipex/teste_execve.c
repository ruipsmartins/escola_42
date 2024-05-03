#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s comando\n", argv[0]);
        return 1;
    }

    char *envp[] = { NULL }; // Lista de variáveis de ambiente, neste caso vazia

    // Executa o comando passado como argumento
    execve("/bin/sh", (char *[]){ "sh", "-c", argv[1], argv[2], NULL }, envp);

    // Se execve retornar, significa que algo deu errado
    perror("execve erro");
    return 1;
}