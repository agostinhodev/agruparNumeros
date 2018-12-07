#include <stdio.h>
#include <stdlib.h>
typedef struct numeros{

	int num;
	int grupo;

	/*
	GRUPOS:
	GRUPO 1[100-105] Números terminados em 0 ou 1 ou 2 ou 3 ou 4 ou 5
	GRUPO 2[110-111] Números terminados em 10 ou 11
	GRUPO 3[113-115] Números terminados em 13 ou 14 ou 15
	GRUPO 4[150] Números terminados em 50
	GRUPO 5: Indefinido
	*/

	struct numeros* proximo;

} Numeros;

void iniciaLista(Numeros *num){

	num->proximo = NULL; 

}

void agrupar(Numeros * listaNumeros, int num){

	Numeros * novo;
	int grupoTemp;
	int finalNum = num % 100;
	
	
	if(finalNum >= 0 && finalNum <= 5){

		/*Primeiro Grupo*/
		grupoTemp = 1;


	} else {

		if(finalNum >= 10 && finalNum <= 11){

			grupoTemp = 2;

		} else {

			if(finalNum >= 13 && finalNum <= 15){

				grupoTemp = 3;


			} else {

				if(finalNum >= 50){

					grupoTemp = 4;

				} else {

					grupoTemp = 5;

				}

			}

		}

	}

	novo = (Numeros *)malloc(sizeof(Numeros));
	novo->num     = num;
	novo->grupo   = grupoTemp;
	novo->proximo = NULL;

	if(listaNumeros->proximo == NULL){

		listaNumeros->proximo = novo;

	}else{

		Numeros *tmp = listaNumeros->proximo;

		while(tmp->proximo != NULL){

			tmp = tmp->proximo;

		}

		tmp->proximo = novo;

	}
 	

}

void imprimir(Numeros * listaNumeros){

	Numeros * temp;
	int i = 1;
	while(i < 5){

		printf("GRUPO %d\n", i);
			
		temp = listaNumeros;
		while(temp != NULL){

			if(temp->grupo == i){

				printf("%d\n", temp->num);

			}
			
			temp = temp->proximo;
		}

		printf("_________________________\n");

		i++;

	}

}

int main(){

	Numeros * num;
	int numTemp, i = 1;
	num = (Numeros *) malloc(sizeof(Numeros));
	iniciaLista(num);

	while(1){

		printf("Numero %d: ", i);
		scanf("%d", &numTemp);
		agrupar(num, numTemp);
		i++;

		if(i == 13){
			/*Essa condição de parada fica a seu criterio*/
			break;

		}

	}

	imprimir(num);

	getchar();
	return 0;

}