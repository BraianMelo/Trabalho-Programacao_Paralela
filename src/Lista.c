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
	
	int contador = 1;
	
	for(int i = 0; i < (n - 1); ++i) {
		if(!lista[i].marcado){
			printf("%d° primo: %d \n", contador, lista[i].numero);
			++contador;
		}
	}
}


bool desalocar_lista(Bloco *lista) {
	if(lista != NULL) {
		free(lista);
		return true;
	}
	
	return false;
}
