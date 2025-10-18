#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "Utilitarios.h"
#include "Lista.h"
#include "Crivo_de_Eratostenes.h"

int main (int argc, char *argv[] ) {
	
	int n = checar_parametros(argc, argv);
	if(!n) {
		return 1;
	}
	
	Bloco *lista = criar_lista(n);
	encontrar_primos(lista, n);
	imprimir_lista(lista, n);

	desalocar_lista(lista);
	return 0;
}
