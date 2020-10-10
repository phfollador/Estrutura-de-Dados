/*
HEAPSORT
O HEAP É UM VETOR QUE SIMULA UMA ÁRVORE BINÁRIA COMPLETA (COM EXCEÇÃO DO ÚLTIMO NÍVEL)
TODO ELEMENTO PAI DO VETOR POSSUI DOIS ELEMENTOS COMO FILHOS
O PAI DEVE SER MAIOR QUE SEUS DOIS FILHOS NO CASO DE UM HEAP MÁXIMO
*/

#include<stdio.h>
#include<stdlib.h>]
#define t 10

//FUNÇÃO PARAR CRIAR O HEAP
//NORMALMENTE, O HEAP USADO NA ORDENAÇÃO É O HEAP MÁXIMO
void criaHeap(int *v, int ini, int fim){
	int aux = v[ini]; //AUXILIAR RECEBE O VALOR INICIAL DA PRIMEIRA PARTIÇÃO (valor PAI)
	int j = ini*2+1; //CALCULANDO O FILHO MAIS A DIREITA
	while(j<=fim){
		if(j<fim){ //FAZ A VERIFICAÇÃO "SE O PAI TEM 2 FILHOS, QUEM É O MAIOR?"
			if(v[j] < v[j+1]){
				j = j+1;
			}
		}if(aux < v[j]){ //CASO O FILHO SEJA MAIOR QUE O PAI, ENTÃO O FILHO DEVE SE TORNAR O PAI
			v[ini] = v[j];
			ini = j;
			j = 2*ini+1;
		}else{
			j = fim+1;
		}
	}v[ini] = aux; //ENTÃO, QUEM ERA O PAI TOMA O LUGAR DO FILHO ANALISADO
}

//FUNÇÃO HEAPSORT
void heapSort(int *v, int n){
	int i, aux;
	//CRIA O HEAP MÁXIMO A PARTIR DA INSERÇÃO DOS DADOS
	for(i = (n-1)/2; i>=0; i--){
		criaHeap(v, i, n-1);
	}

	for(i = n-1; i >= 1; i--){
		//COLOCANDO O MAIOR ELEMENTO NA SUA POSIÇÃO CORRETA DO VETOR
		//NORMALMENTE NO FINAL
		aux = v[0];
		v[0] = v[i];
		v[i] = aux;
		criaHeap(v, 0, i-1); //RECONSTROI O HEAP
	}
}

//FUNÇÃO MAIN
int main(void){
		
	int v[t];
	int i, size = sizeof(v)/sizeof(v[0]);
	
	//PREENCHENDO O VETOR COM VALORES DO TECLADO
	for(i = 0; i < t; i++){
		printf("VALOR: ");
		scanf("%d",&v[i]);
	}
	
	//LIMPANDO A TELA
	system("cls");
	
	//CHAMANDO A FUNÇÃO PARA ORDENAR O VETOR
	heapSort(v, size);
	
	//IMPRIMINDO NA TELA O VETOR JÁ ORDENADO
	printf("ORDENADO: ");
	for(i = 0; i<t; i++){
		printf("%d ", v[i]);
	}
	
	return 0;
}
