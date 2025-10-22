#include "Crivo_de_Eratostenes.h"

bool encontrar_primos(Bloco *lista, int n) {
	if(lista == NULL) {
		printf("ERRO: Lista vazia! \n");
		return false;
	}
	
	int p_max = (int) floor(sqrt(n)); 
	
	int numero, contador, resultado;
	
	for(int i = 0; i < (p_max); ++i) { 
		if(lista[i].marcado)
			continue;
		
		numero = lista[i].numero;
		contador = 2;
		resultado;
		
		while(1) {
            resultado = numero * contador;

            if (resultado > n) { 
                break;
            }
            
            if (resultado - 2 < n) {
                lista[resultado - 2].marcado = true;
            } else {
                break; 
            }
            
			++contador;
		}
	}
	
	return true;
}


bool encontrar_primos_MPI(Bloco *lista, int n) {
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	if(lista == NULL) {
		printf("ERRO: Lista vazia! \n");
		return false;
	}
	
	int p_max = (int) floor(sqrt(n)); 
	int intervalo = n / size;
	int inicio = rank * intervalo;
	int final;
	
	if(rank == (size - 1)){
		final = n;
		
	} else {
		final = rank * intervalo - 1;
		
	}
}

