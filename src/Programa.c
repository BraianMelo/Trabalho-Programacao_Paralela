#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <mpi.h>

#include "Utilitarios.h"
#include "Lista.h"
#include "Crivo_de_Eratostenes.h"

int main (int argc, char *argv[] ) {
	MPI_Init(&argc, &argv);
	
	char modo;
	int n = checar_parametros(argc, argv, &modo);
	
	if(!n) {
		MPI_Finalize();
		return 1;
	}
	
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	printf("Rank: %d\n", rank);
	
	Bloco *lista = criar_lista(n);
	encontrar_primos(lista, n);
	imprimir_lista(lista, n);

	desalocar_lista(lista);
	MPI_Finalize();
	return 0;
}
