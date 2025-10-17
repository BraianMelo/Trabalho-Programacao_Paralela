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

bool encontrar_primos(Bloco *lista, int n) {
	if(lista == NULL) {
		printf("ERRO: Lista vazia! \n");
		return false;
	}
	
	int p_max = (int) floor(sqrt(n)); 
	
	for(int i = 0; i < (p_max); ++i) { 
		if(lista[i].marcado)
			continue;
		
		int numero = lista[i].numero;
		int contador = 2;
		int resultado;
		
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


bool desalocar_lista(Bloco *lista) {
	if(lista != NULL) {
		free(lista);
		return true;
	}
	
	return false;
}
