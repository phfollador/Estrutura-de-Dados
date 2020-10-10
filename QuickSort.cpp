/*

QUICK SORT

ORDENA��O POR TROCA DE PARTI��ES
IDEIA B�SICA � DIVIDIR PARA CONQUISTAR
UM ELEMENTO � ESCOLHIDO COMO PIV�
O PARTICIONAR TEM A IDEIA DE QUE OS DADOS S�O REARRANJADOS COLOCANDO OS VALORES MENORES QUE O PIV� ANTES E OS MAIORES DEPOIS
RECURSIVAMENTE ORDENA AS 2 PARTI��ES

MELHOR CASO: O(n log n)
PIOR CASO (raro): O(n^2)
� UM ALGORITMO EST�VEL
A DESVANTAGEM � ESCOLHER O PIV�
*/

#include<stdio.h>
#include<stdlib.h>

#define t 10

//FUN��O QUE REALIZA O PARTICIONAMENTO
int particiona(int *v, int inicio, int final){
	
	int esq, dir, pivo, aux;
	esq = inicio;
	dir = final;
	pivo = v[inicio]; //PIVO RECEBE O INCIO DO VETOR
	
	while(esq<dir){
		while(v[esq]<=pivo) esq++; //AVAN�A PARA ESQUERDA
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

//FUN��O QUICK SORT
void quickSort(int *v, int inicio, int fim){
	
	int pivo;
	
	if(fim>inicio){
		pivo = particiona(v, inicio, fim); //REALIZA O PARTICIONAMENTO DO VETOR
		quickSort(v, inicio, pivo-1); //ORDENA DO INICIO AT� O MEIO
		quickSort(v, pivo+1, fim); // ORDENA DO MEIO+1 AT� O FIM
	}
}

//FUN��O MAIN
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
	
	//CHAMANDO A FUN��O PARA ORDENAR O VETOR
	quickSort(v, 0, size-1);
	
	//IMPRIMINDO NA TELA O VETOR J� ORDENADO
	printf("ORDENADO: ");
	for(i = 0; i<t; i++){
		printf("%d ", v[i]);
	}
	
	return 0;
}
