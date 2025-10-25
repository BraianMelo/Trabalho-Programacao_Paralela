#ifndef LISTA_H
#define LISTA_H


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 8192

typedef struct bloco {
	int numero;
	bool marcado;
} Bloco;

typedef struct lista {
	int n;
	int qtd;
	int qtd_primos;
	Bloco *elementos;
} Lista;

Lista* criar_lista(int n);
void imprimir_lista(Lista *lista);
void gerar_arquivo_primos(Lista *lista);
int* retornar_lista_primos(Lista *lista);
bool desalocar_lista(Lista *lista);


#endif
