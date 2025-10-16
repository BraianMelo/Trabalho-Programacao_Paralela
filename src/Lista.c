#include "Lista.h"

Bloco* criar_lista(int n) {
	Bloco *lista = malloc(n * sizeof(Bloco));
	
	for(int i = 0; i < (n - 1); ++i) {
		lista[i].numero = i + 2;
		lista[i].marcado = false;
	}
	
	return lista;
}

void imprimir_lista(Bloco *lista, int n) {
	for(int i = 0; i < (n - 1); ++i) {
		if(!lista[i].marcado)
			printf("Lista[%d] = %d \n", i, lista[i].numero);
	}
}
