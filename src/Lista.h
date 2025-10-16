#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct bloco {
	int numero;
	bool marcado;
} Bloco;

Bloco* criar_lista(int n);
void imprimir_lista(Bloco *lista, int n);
