//M�TODO DE ORDENA��O POR SELE��O

#include<stdio.h>
#include<stdlib.h>

//FUN��O PARA REALIZAR A ORDENA��O POR SELE��O
void ordena(vet[10]){
	
	int i, j, min;
	int aux;
	
	for(i = 1; i < vet-1; i++){
		min = i;
		for(j = i+1; j < n; j++){
			if(vet[j] < vet[min]){
				min = j;
			}else{
				aux = vet[min];
				vet[min] = vet[i];
				vet[i] = aux;
			}
		}
	}
	
	//IMPRIMINDO O VETOR ORDENADO
	for(i = 0; i <= 10; i++){
		printf("VALOR: %d\n", vet[i]);
	}
}

int main(void){
	
	int vet[10];
	int i;
	
	//INSERINDO ELEMENTOS NO VETOR
	for(i = 0; i <= 10; i++){
		printf("VALOR: ");
		scanf("%d", vet[i]);
	}
	
	ordena(vet[10]);
}
