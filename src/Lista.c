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

bool encontrar_primos(Bloco *lista, int n) {
	if(lista == NULL) {
		printf("ERRO: Lista vazia! \n");
		return false;
	}
	
	int p_max = (int) floor(sqrt(n)); // Ele corresponde à raiz quadrada do valor limite, arredondado para baixo.
	
	for(int i = 0; i < (n-1); ++i) {
		if(lista[i].marcado)
			continue;
		
		int numero = lista[i].numero;
		int contador = 2;
		int resultado;
		
		do {
			resultado = numero * contador;
			
			lista[resultado - 2].marcado = true;
			
			++contador;
			
		} while(resultado < n);
		
	}
	
	return true;
}


bool desalocar_lista(Bloco *lista) {
	if(lista != NULL) {
		free(lista);
		return true;
	}
	return false;
}
