#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "Utilitarios.h"

int main (int argc, char *argv[] ) {
	
	int n = checar_parametros(argc, argv);
	
	if(!n) {
		return 1;
	}
	
	int *lista = (int *) malloc(n * sizeof(int));
	
	for(int i = 0; i < n; ++i) {
		lista[i] = i + 2;
	}
	
	for(int i = 0; i < n; ++i) {
		printf("%d ", lista[i]);
	}
	printf("\n");

	free(lista);
	return 0;
}
