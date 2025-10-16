#include "Utilitarios.h"

int checar_parametros(int argc, char* argv[]){
	
	int n = 0;

	switch(argc){
		case 1:
			printf("Informe o N: ");
			scanf("%d", &n);
			
			if(!checar_N(n)){
				return 0;
			}
			
			return n;
			
		case 2:
			n = atoi(argv[1]);
			
			if(!checar_N(n)){
				return 0;
			}
			
			return n;
		
		default:
			printf("Numeros de parâmetros inválidos! \n");
			printf("Você pode passar N como parâmetro ou por linha. \n");
			return n;
	}

}


bool checar_N(int n) {
	if(n < 2) {
		printf("O N deve ser maior ou igual a 2! \n");
		return false;
	}
	
	return true;
}
