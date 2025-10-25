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
                if (!lista->elementos[resultado - 2].marcado) {
					lista->elementos[resultado - 2].marcado = true;
					--(lista->qtd_primos); 
				}
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

    int n = lista->n;
    int p_max = (int) floor(sqrt(n));

    int qtd_primos_pequenos;
    int *primos_pequenos = NULL;
    MPI_Barrier(MPI_COMM_WORLD);

    if(rank == 0) {
        Lista *primos_pequenos_tmp = criar_lista(p_max);
        encontrar_primos(primos_pequenos_tmp);
        primos_pequenos = retornar_lista_primos(primos_pequenos_tmp);
        qtd_primos_pequenos = primos_pequenos_tmp->qtd_primos;
        desalocar_lista(primos_pequenos_tmp);
    }

    MPI_Bcast(&qtd_primos_pequenos, 1, MPI_INT, 0, MPI_COMM_WORLD);
    
    if(rank != 0) 
		primos_pequenos = malloc(qtd_primos_pequenos * sizeof(int));
		
    MPI_Bcast(primos_pequenos, qtd_primos_pequenos, MPI_INT, 0, MPI_COMM_WORLD);

    int bloco = (lista->qtd + size - 1) / size;
    int inicio = rank * bloco;
    int fim = inicio + bloco;
    if(fim > lista->qtd) 
		fim = lista->qtd;

    bool *local_marcado = calloc(lista->qtd, sizeof(bool));

    int primeiro_numero_bloco = lista->elementos[inicio].numero;
    int ultimo_numero_bloco = lista->elementos[fim - 1].numero;
    
    int numero, contador, resultado; 

    for (int i = 0; i < qtd_primos_pequenos; ++i) {
        numero = primos_pequenos[i]; 
        
        int start = ((primeiro_numero_bloco + numero - 1) / numero) * numero;
        
        if (start < numero * numero) {
            start = numero * numero;
        }

        contador = start / numero;

        resultado = 0;
        
        while(1) {
            resultado = numero * contador; 

            if (resultado > ultimo_numero_bloco) { 
                break;
            }
            
            local_marcado[resultado - 2] = true;
            ++contador;
        }
    }

    bool *global_marcado = NULL;
    if(rank == 0) 
		global_marcado = calloc(lista->qtd, sizeof(bool));
		
	
	MPI_Barrier(MPI_COMM_WORLD);
    MPI_Reduce(local_marcado, global_marcado, lista->qtd, MPI_C_BOOL, MPI_LOR, 0, MPI_COMM_WORLD);

    if(rank == 0) {
        for(int i = 0; i < lista->qtd; ++i)
            lista->elementos[i].marcado = global_marcado[i];
        free(global_marcado);
    }

    free(local_marcado);
    free(primos_pequenos);
    return true;
}
