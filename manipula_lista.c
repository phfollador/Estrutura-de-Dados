#include<stdio.h>
#include<stdlib.h>

#define n 5

//função para encontrar o elemento maximo do vetor

int maximo(int a[], int tamanho){
	if(tamanho == 1) return a[0];
	else if(a[tamanho - 1] > maximo(a, tamanho - 1)) return (a[tamanho - 1]);
	else return maximo(a, tamanho - 1);
}

//função para encontrar o menor elemento de um vetor
int minimo(int a[], int tamanho){
	if(tamanho == 1) return a[0];
	else if(a[tamanho - 1] < minimo(a, tamanho - 1)) return (a[tamanho - 1]);
	else return minimo(a, tamanho - 1);
}

//função para somar os elementos de um vetor
int somatorio(int a[], int tamanho){
	if(tamanho == 1) return a[0];
	else{
		return a[tamanho - 1] + somatorio(a, tamanho - 1);
	}
}

//função para apresentar o produto dos elementos de um vetor
int produto(int a[], int tamanho){
	if(tamanho == 1) return a[0];
	else{
		return a[tamanho - 1] * produto(a, tamanho - 1);
	}
}

//função para calcular a media dos elementos de um vetor
float media(int a[], int tamanho){
	if(tamanho == 1) return a[0];
	else{
		return a[tamanho - 1] + media(a, tamanho - 1);
	}
}

int main(void){
	int a[n];
	int i;

	for(i = 0; i < n; i++){
		printf("ENTRE COM O ELEMENTO[%d]: ", (i+1));
		scanf("%d", &a[i]);
	}
	printf("seu vetor: ");
	for(i = 0; i < n; i++){
		printf("%d: ", a[i]);
	}

	int max = maximo(a, n);
	printf("\no maior elemento do vetor e: %d\n", max);

	int min = minimo(a, n);
	printf("o menor elemento do vetor e: %d\n", min);

	int resultado = somatorio(a, n);
	printf("a soma dos elementos do vetor e: %d\n", resultado);

	int product = produto(a, n);
	printf("o produto dos elementos do vetor e: %d\n", product);

	float med = media(a, n);
	printf("a media dos elementos do vetor e: %.2f\n", med/n);
return 0;
}
