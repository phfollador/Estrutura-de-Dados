/*
INSERTION SORT

EFICIENTE PARA CONJUNTOS PEQUENOS DE DADOS
� EST�VEL, OU SEJA, N�O ATERA A ORDEM DOS DADOS IGUAIS
CAPAZ DE ORDENAR DADOS � MEDIDA EM QUE OS RECEBE (TEMPO REAL)
*/

#include<stdio.h>
#include<stdlib.h>

#define tam 10

//FUN��O INSERTION SORT
void insertionSort(int *v, int n){
	
	int i, j, aux;
	
	for(i = 0; i < n; i++){ //PERCORRENDO O VETOR E ALOCANDO O AUXILIAR
		aux = v[i];
		for(j = i; (j>0) && (aux<v[j-1]); j--){//PERCORRENDO E COMPARANDO UMA POSI��O i COM OS OUTROS
			v[j] = v[j-1];
		}
		v[j] = aux;//ATRIBUINDO O VALOR DIGITADO NO SEU DEVIDO LUGAR
	}
}

//FUN��O MAIN
int main(void){
	
	int v[tam];
	int i, valor = sizeof(v)/sizeof(v[0]);
	
	//PREENCHENDO O VETOR COM VALORES DO TECLADO
	for(i = 0; i < tam; i++){
		printf("VALOR: ");
		scanf("%d",&v[i]);
	}
	
	//LIMPANDO A TELA
	system("cls");
	
	//CHAMANDO A FUN��O PARA ORDENAR O VETOR
	insertionSort(v, valor);
	
	//IMPRIMINDO NA TELA O VETOR J� ORDENADO
	printf("ORDENADO: ");
	for(i = 0; i<tam; i++){
		printf("%d ", v[i]);
	}
	
	return 0;
}
