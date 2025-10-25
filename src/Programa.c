#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>

#include "Utilitarios.h"
#include "Lista.h"
#include "Crivo_de_Eratostenes.h"

int main (int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    char modo;
    int n = checar_parametros(argc, argv, &modo);

    if (!n) {
        if (rank == 0) {
            fprintf(stderr, "ERRO: Parâmetros inválidos!\n");
            fprintf(stderr, "Uso correto: mpirun -np <num_processos> ./programa <N> <modo>\n");
            fprintf(stderr, "  <N>    : número inteiro >= 2\n");
            fprintf(stderr, "  <modo> : 's' para sequencial ou 'p' para paralelo\n\n");
        }
        MPI_Finalize();
        return 1;
    }

    if (rank == 0) {
        printf("Modo selecionado: %s", (modo == 's'? "sequencial.\n": "paralelo.\n"));
        printf("Calculando primos até %d:\n", n);
    }

    Lista *lista = criar_lista(n);

    if (modo == 's' || modo == 'S') {
        if (rank == 0) {
            encontrar_primos(lista);
            gerar_arquivo_primos(lista);
            printf("Lista de primos guardada no arquivo primos.txt. \n");
        }
    } 
    else if (modo == 'p' || modo == 'P') {
        encontrar_primos_MPI(lista);

        if (rank == 0) {
            gerar_arquivo_primos(lista);
            printf("Lista de primos guardada no arquivo primos.txt. \n");
        }
    }
    

    desalocar_lista(lista);
    MPI_Finalize();
    return 0;
}
