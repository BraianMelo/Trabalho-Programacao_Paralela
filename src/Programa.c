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

    char modo;
    int n = checar_parametros(argc, argv, &modo);

    if (!n) {
        MPI_Finalize();
        return 1;
    }

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        printf("Modo selecionado: %c\n", modo);
        printf("Procurando primos até %d...\n", n);
    }

    Bloco *lista = criar_lista(n);

    if (modo == 's' || modo == 'S') {
        if (rank == 0) {
            encontrar_primos(lista, n);
            imprimir_lista(lista, n);
            
        }
    } else if (modo == 'p' || modo == 'P') {
        encontrar_primos_MPI(lista, n);

        if (rank == 0)
            imprimir_lista(lista, n);
    } 
    else {

        free(lista);
        MPI_Finalize();
        return 1;
    }

    desalocar_lista(lista);
    MPI_Finalize();
    return 0;
}
