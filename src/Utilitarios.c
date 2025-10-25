#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Utilitarios.h"

int checar_parametros(int argc, char* argv[], char *modo) {
    int n = 0;

    if (argc == 3) {
        n = atoi(argv[1]);

        if (!checar_N(n))
            return 0;

        *modo = argv[2][0];

        if (!checar_modo(*modo))
            return 0;

    }
    return n;
}

bool checar_N(int n) {
    if (n < 2) {
        printf("O N deve ser maior ou igual a 2!\n");
        return false;
    }
    return true;
}

bool checar_modo(char modo) {
    if (modo == 'p' || modo == 's')
        return true;

    printf("O modo deve ser 'p' para paralelo ou 's' para sequencial!\n");
    return false;
}
