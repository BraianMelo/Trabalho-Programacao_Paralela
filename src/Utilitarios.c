#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Utilitarios.h"

int checar_parametros(int argc, char* argv[], char *modo){
	
	int n = 0;

	switch(argc){
		case 1:
			printf("Informe o N: ");
			
			if (scanf("%d", &n) != 1) {
				printf("ERRO: Entrada de N inválida ou formato incorreto.\n");
				while (getchar() != '\n'); 
				return 0;
			}
			
			if(!checar_N(n)){
				return 0;
			}
			
			printf("Informe o modo ('s' ou 'p'): ");
			
			if (scanf(" %c", modo) != 1) {
				printf("ERRO: Entrada de modo inválida ou formato incorreto.\n");
				while (getchar() != '\n'); 
				return 0;
			}
			
			if(!checar_modo(*modo)) {
				return 0;
			}
			
			return n;
			
		case 3:
			n = atoi(argv[1]);
			
			if(!checar_N(n)){
				return 0;
			}
			
			*modo = argv[2][0];
			
			if(!checar_modo(*modo)){
				return 0;
			}
			
			return n;
		
		default:
			printf("Número de parâmetros inválido!\n");
			printf("Uso correto:\n");
			printf("  ./programa <N> <modo>\n");
			printf("    <N>    : número inteiro >= 2\n");
			printf("    <modo> : 's' para sequencial ou 'p' para paralelo\n");
			printf("\nExemplo:\n");
			printf("  ./programa 100 p\n");
			printf("\nCaso não informe parâmetros, o programa solicitará N e o modo manualmente.\n");
			return 0;
	}
}

bool checar_N(int n) {
	if(n < 2) {
		printf("O N deve ser maior ou igual a 2! \n");
		return false;
	}
	return true;
}

bool checar_modo(char modo) {
	if (modo == 'p' || modo == 's')
		return true;
		
	printf("O modo deve ser 'p' para paralelo ou 's' para sequencial! \n");
	return false;
}
