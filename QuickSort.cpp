/*

QUICK SORT

ORDENAÇÃO POR TROCA DE PARTIÇÕES
IDEIA BÁSICA É DIVIDIR PARA CONQUISTAR
UM ELEMENTO É ESCOLHIDO COMO PIVô
O PARTICIONAR TEM A IDEIA DE QUE OS DADOS SÃO REARRANJADOS COLOCANDO OS VALORES MENORES QUE O PIVÔ ANTES E OS MAIORES DEPOIS
RECURSIVAMENTE ORDENA AS 2 PARTIÇÕES

MELHOR CASO: O(n log n)
PIOR CASO (raro): O(n^2)
É UM ALGORITMO ESTÁVEL
A DESVANTAGEM É ESCOLHER O PIVÔ
*/

#include<stdio.h>
#include<stdlib.h>

#define t 10

//FUNÇÃO QUE REALIZA O PARTICIONAMENTO
int particiona(int *v, int inicio, int final){
	
	int esq, dir, pivo, aux;
	esq = inicio;
	dir = final;
	pivo = v[inicio]; //PIVO RECEBE O INCIO DO VETOR
	
	while(esq<dir){
		while(v[esq]<=pivo) esq++; //AVANÇA PARA ESQUERDA
		while(v[dir]>pivo) dir--; //VOLTA PARA DIREITA
		
		if(esq<dir){ //REALIZAR A TROCA ENTRE ESQUERDA E DIREITA
			aux = v[esq];
			v[esq] = v[dir];
			v[dir] = aux;
		}
	}
	v[inicio] = v[dir];
	v[dir] = pivo;
	return dir;
}

//FUNÇÃO QUICK SORT
void quickSort(int *v, int inicio, int fim){
	
	int pivo;
	
	if(fim>inicio){
		pivo = particiona(v, inicio, fim); //REALIZA O PARTICIONAMENTO DO VETOR
		quickSort(v, inicio, pivo-1); //ORDENA DO INICIO ATÉ O MEIO
		quickSort(v, pivo+1, fim); // ORDENA DO MEIO+1 ATÉ O FIM
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
	quickSort(v, 0, size-1);
	
	//IMPRIMINDO NA TELA O VETOR JÁ ORDENADO
	printf("ORDENADO: ");
	for(i = 0; i<t; i++){
		printf("%d ", v[i]);
	}
	
	return 0;
}
