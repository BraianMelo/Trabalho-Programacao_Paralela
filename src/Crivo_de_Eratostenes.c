#include "Crivo_de_Eratostenes.h"

bool encontrar_primos(Lista *lista) {
	if(lista == NULL) {
		printf("ERRO: Lista vazia! \n");
		return false;
	}
	
	int p_max = (int) floor(sqrt(lista->n)); 
	
	int numero, contador, resultado;
	
	for(int i = 0; i < (p_max); ++i) { 
		if(lista->elementos[i].marcado)
			continue;
		
		numero = lista->elementos[i].numero;
		contador = 2;
		resultado = 0;
		
		while(1) {
            resultado = numero * contador;

            if (resultado > lista->n) { 
                break;
            }
            
            if (resultado - 2 < lista->n) {
                lista->elementos[resultado - 2].marcado = true;
                --(lista->qtd_primos);
            } else {
                break; 
            }
            
			++contador;
		}
	}
	
	return true;
}

bool encontrar_primos_MPI(Lista *lista) {
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (lista == NULL) {
        if (rank == 0)
            printf("ERRO: Lista vazia!\n");
        return false;
    }

    int n = lista->n;
    int p_max = (int)floor(sqrt(n));

    Lista *primos_pequenos = NULL;
    if (rank == 0) {
        primos_pequenos = criar_lista(p_max);
        encontrar_primos(primos_pequenos);
        imprimir_lista(primos_pequenos);

		int qtd_primos = primos_pequenos->qtd_primos;
		int *vetor_primos = retornar_lista_primos(primos_pequenos);
		
		for(int i = 0; i < qtd_primos; ++i) {
			printf("%d \n", vetor_primos[i]);
		}
		
		desalocar_lista(primos_pequenos);
		free(vetor_primos);
	}
	return true;

}
