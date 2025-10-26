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

void imprimir_lista(Lista *lista) {
    if (lista == NULL || lista->elementos == NULL) {
        fprintf(stderr, "Lista inválida.\n");
        return;
    }

    char *buffer = (char *)malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        fprintf(stderr, "Erro ao alocar buffer de impressão. Imprimindo diretamente.\n");
    }

    int buffer_offset = 0;
    int contador = 1;
    int len;

    for (int i = 0; i < lista->qtd; ++i) {
        if (!lista->elementos[i].marcado) {
            len = snprintf(buffer + buffer_offset,
                           BUFFER_SIZE - buffer_offset,
                           "%d° primo: %d, ", contador, lista->elementos[i].numero);

            if (len < 0 || buffer_offset + len >= BUFFER_SIZE) {
                printf("%s", buffer);
                buffer_offset = 0;
                len = snprintf(buffer + buffer_offset,
                               BUFFER_SIZE - buffer_offset,
                               "%d° primo: %d, ", contador, lista->elementos[i].numero);
            }

            buffer_offset += len;
            ++contador;
        }
    }

    if (buffer_offset > 0) {
        printf("%s", buffer);
    }

    printf("\n");

    free(buffer);
}



void gerar_arquivo_primos(Lista *lista) {
    if (lista == NULL || lista->elementos == NULL) {
        fprintf(stderr, "Lista inválida.\n");
        return;
    }

    FILE *arquivo = fopen("primos.txt", "w");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao criar arquivo de saída 'primos.txt'.\n");
        return;
    }

    char *buffer = (char *)malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        fprintf(stderr, "Erro ao alocar buffer de impressão.\n");
        fclose(arquivo);
        return;
    }

    int buffer_offset = 0;
    int contador = 1;
    int len;

    for (int i = 0; i < lista->qtd; ++i) {
        if (!lista->elementos[i].marcado) {
            len = snprintf(buffer + buffer_offset,
                           BUFFER_SIZE - buffer_offset,
                           "%d° primo: %d \n", contador, lista->elementos[i].numero);

            if (len < 0 || buffer_offset + len >= BUFFER_SIZE) {
                fprintf(arquivo, "%s", buffer);
                buffer_offset = 0;
                len = snprintf(buffer + buffer_offset,
                               BUFFER_SIZE - buffer_offset,
                               "%d° primo: %d \n", contador, lista->elementos[i].numero);
            }

            buffer_offset += len;
            ++contador;
        }
    }

    if (buffer_offset > 0) {
        fprintf(arquivo, "%s", buffer);
    }
    
    fprintf(arquivo, "\n");

    free(buffer);
    fclose(arquivo);
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
