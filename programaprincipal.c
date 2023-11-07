#include <stdio.h>
#include "funciones.h"

int main(){
	int op1;
	int op2;
	int res;
	float resf;
	int option;
	printf("Menu: \n");
	printf("1 - Sumar \n 2 - Restar - \n 3 - MUltiplicar \n 4 - Dividir \n S- Salir \n");
	printf("Seleccione una opcion del menu");
	scanf("%d", &option);
	printf("Indique el operando 1: ");
	scanf("%d", &op1);
	printf("Indique el operando 2: ");
	scanf("%d", &op2);

	switch (option) {
	case 1: 
		res = sumar(op1,op2);
		printf("El resultado de la operacion es: %d \n", res);
		break;
	
	case 2: 
		res = restar(op1,op2);
		printf("El resultado de la operacion es: %d \n", res);
		break;
	
	case 3: 
		res = multiplicar(op1,op2);
		printf("El resultado de la operacion es: %d \n", res);
		break;

	case 4:
		resf = dividir(op1,op2);	
		printf("El resultado de la operacion es: %f \n", resf);
		break;

	case 5:
		printf("Saliendo");
		break;
	
	default:
		printf("Operacion no reconocida \n");
		break;
	
	}
	return 0;
	
	}

