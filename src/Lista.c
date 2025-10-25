#include "Lista.h"

Lista* criar_lista(int n) {
	Lista *lista = malloc(sizeof(Lista));
	lista->n = n;
	lista->qtd = n - 1;
	lista->qtd_primos = lista->qtd;
	
	lista->elementos = malloc(lista->qtd * sizeof(Bloco));
	
	for(int i = 0; i < lista->qtd; ++i) {
		lista->elementos[i].numero = i + 2;
		lista->elementos[i].marcado = false;
	}
	
	return lista;
}

void imprimir_lista(Lista *lista) {
	
	int contador = 1;
	
	for(int i = 0; i < (lista->qtd); ++i) {
		if(!lista->elementos[i].marcado){
			printf("%d° primo: %d \n", contador, lista->elementos[i].numero);
			++contador;
		}
	}
}

int* retornar_lista_primos(Lista *lista) {
    if (lista == NULL || lista->elementos == NULL || lista->qtd_primos <= 0) {
        return NULL;
    }

    int qtd_primos = lista->qtd_primos;
    int *lista_primos = malloc(qtd_primos * sizeof(int));
    
    if (lista_primos == NULL) {
        printf("Erro ao alocar memória para lista de primos!\n");
        return NULL;
    }

    int contador = 0;
    for (int i = 0; i < lista->qtd && contador < qtd_primos; ++i) {
        if (lista->elementos[i].marcado == false) {
            lista_primos[contador++] = lista->elementos[i].numero;
        }
    }

    return lista_primos;
}


bool desalocar_lista(Lista *lista) {
	if(lista != NULL) {
		if(lista->elementos != NULL) {
			free(lista->elementos);
		}
		
		free(lista);
		return true;
	}
	
	return false;
}
