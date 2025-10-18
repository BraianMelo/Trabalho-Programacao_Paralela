#ifndef LISTA_H
#define LISTA_H


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct bloco {
	int numero;
	bool marcado;
} Bloco;

Bloco* criar_lista(int n);
void imprimir_lista(Bloco *lista, int n);
bool desalocar_lista(Bloco *lista);


#endif
