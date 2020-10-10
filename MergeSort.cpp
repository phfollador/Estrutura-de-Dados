/*
MERGE SORT

TAMBÉM CONHECIDO COMO ORDENAÇÃO POR MISTURA
SUA IDEIA BÁSICA É O DIVIDIR PARA CONQUISTAR
DIVIDE RECURSIVAMENTE O CONJUNTO DE DADOS ATE QUE CADA SUBCONJUNTO POSSUA 1 ELEMENTO
COMBINA 2 SUBCONJUNTOS DE FORMA A OBTER 1 CONJUNTO MAIOR ORDENADO
É ESTÁVEL, SEU MELHOR CASO É O(n log n) E O PIOR CASO TAMBÉM É O(n log n)
UTILIZA UM VETOR AUXILIAR NO MOMENTO DA ORDENÇÃO, ISSO CRIA UMA GRANDE DESVANTAGEM

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define t 10

//FUNÇÃO MERGE
void merge(int *v, int inicio, int meio, int fim){
	
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim-inicio+1;
	p1 = inicio;
	p2 = meio+1;
	
	//VETOR TEMP ALOCADO PARA SER PREENCHIDO COM P1 E P2 ORDENADOS
	//NESSE MOMENTO EXISTE UM GASTO DE MEMÓRIA A MAIS
	temp = (int *) malloc(tamanho*sizeof(int));
	
	if(temp != NULL){
		for(i=0; i<tamanho; i++){//PERCORRENDO O VETOR TEMP
			if(!fim1 && !fim2){
				//PERCORRO CADA POSICAO DO VETOR TEMP E VERIFICO QUEM É O MENOR ELEMENTO DOS VETORES P1 E P2
				//COMBINAÇÃO ORDENADA
				if(v[p1]<v[p2]){
					temp[i] = v[p1++];
				}else{
					temp[i] = v[p2++];
				}
				//VERIFICA SE O VETOR ACABOU
				if(p1>meio) fim1 = 1;
				if(p2>fim) fim2 = 1;
			}else{
				//COPIA O QUE SOBRAR DOS VETORES
				if(!fim1){
					temp[i] = v[p1++];
				}else{
					temp[i] = v[p2++];
				}
			}
		}
		//REPETIÇÃO QUE COPIA DO VETOR AUXILIAR PARA O ORIGINAL
		for(j = 0, k=inicio; j<tamanho; j++, k++){
			v[k] = temp[j];
		}
	}
	//LIMAPANDO O VETOR AUXILIAR
	free(temp);
}

//FUNÇÃO MERGE SORT
void mergeSort(int *v, int inicio, int fim){
	int meio;
	if(inicio<fim){
		meio = floor((inicio+fim)/2); //ENCONTRAR O MEIO DO VETOR PARA DIVIDI-LO
		mergeSort(v, inicio, meio); //PRIMEIRA METADE
		mergeSort(v, meio+1, fim);	//SEGUNDA METADE
		merge(v, inicio, meio, fim); //COMBINA AS DUAS METADES DE FORMA ORDENADA	
	}
}

//FUNÇÃO MAIN
int main(void){
	
	int v[t];
	int size = sizeof(v)/sizeof(v[0]);
	int i;
	
	//PREENCHENDO O VETOR COM VALORES DO TECLADO
	for(i = 0; i < t; i++){
		printf("VALOR: ");
		scanf("%d",&v[i]);
	}
	
	//LIMPANDO A TELA
	system("cls");
	
	//CHAMANDO A FUNÇÃO PARA ORDENAR O VETOR
	mergeSort(v, 0, size-1);
	
	//IMPRIMINDO NA TELA O VETOR JÁ ORDENADO
	printf("ORDENADO: ");
	for(i = 0; i<t; i++){
		printf("%d ", v[i]);
	}
	
	return 0;
}
