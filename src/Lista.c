#include "Lista.h"

int* criar_lista(int n) {
	int *lista = malloc(n * sizeof(int));
	
	for(int i = 0; i < n; ++i) {
		lista[i] = i + 2;
	}
	
	return lista;
}

void imprimir_lista(int *lista, int n) {
	for(int i = 0; i < n; ++i) {
		printf("Lista[%d] = %d \n", i, lista[i]);
	}
}
