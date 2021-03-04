#include<stdio.h>
#include<stdlib.h>

//criando a estrutura para uma lista simplesmente encadeada de numeros inteiros
typedef struct node{
	int chave;
	struct node * prox;
} Node;

//inicialização de uma lista sempre vazia
Node * L = NULL;

//função para inserir um elemento no inicio da lista
Node * insereInicio(Node * L, int chave){
	Node * novo = (Node *) calloc(1, sizeof(Node));
	if(novo != NULL){
		novo->chave = chave;
		novo->prox = NULL;
		novo->prox = L;
	}
	else{
		printf("ERRO DE ALOCACAO!\n");
	}
	return novo;
}

//função para imprimir o conteudo de uma lista na tela
void imprimir(Node * L){
	Node * aux = L;
	while(aux != NULL){
		printf("%d->", aux->chave);
		aux = aux->prox;
	}
}


//função para buscar por uma chave na lista
Node * buscar(Node * L, int ch){
	Node * aux = L;
	while(aux != NULL){
		if(aux->chave == ch){
			return aux;
		}
		aux = aux->prox;
	}
	return aux;
}

//função para excluir o primeiro no da lista
Node * removeInicio(Node * L){
	Node * aux = L;
	if(aux != NULL) L = L->prox;
	free(aux);
	return L;
}

//função para inserir um nó no final da lista
Node * insereFinal(Node * L, int ch){
	Node * aux = L;
	Node * novo = (Node *) calloc(1, sizeof(Node));
	while(aux != NULL){
		if(aux->prox == NULL) break;
		aux = aux->prox;
	}
	if(aux == NULL) return novo;
	aux->prox = novo;
	return L;
}

//função que remove o último elemento da lista
Node * removeUltimo(Node * L){
	Node * aux = L;
	Node * ant = NULL;
	if(L == NULL) return L;
	while(aux->prox != NULL){
		ant = aux;
		aux = aux->prox;
	}
	if(ant == NULL) L = NULL;
	else{
		ant->prox = NULL;
	}
	free(aux);
	return L;
}

//função para remover um elemento dado uma chave
Node * removeChave(Node * L, int ch){
	Node * aux = buscar(L, ch);
	Node * ant = L->prox;
	if(aux == NULL) return L;
	else free(aux);
	return L;
}

int main(){
	Node * L = NULL;
	int op = 0, valor = 0;

	do{
		printf("MENU\n");
		printf("1- INSERIR NO INICIO\n");
		printf("2- INSERIR NO FINAL\n");
		printf("3- REMOVER NO INICIO\n");
		printf("4- REMOVER NO FINAL\n");
		printf("5- REMOVER UMA CHAVE\n");
		printf("6- IMPRIMIR\n");
		printf("7- BUSCAR\n");
		printf("0- SAIR\n");
		scanf("%d", &op);

		switch(op){
			case 1:
				printf("INFORME O ELEMENTO QUE DESEJA INSERIR: ");
				scanf("%d", &valor);
				L = insereInicio(L, valor);
			break;

			case 2:
				printf("INFORME O ELEMENTO QUE DESEJA INSERUR: ");
				scanf("%d", &valor);
				insereFinal(L, valor);
			break;

			case 3:
				removeInicio(L);
			break;

			case 4:
				removeUltimo(L);
			break;

			case 5:
				printf("INFORME O ELEMENTO QUE DESEJA REMOVER: ");
				scanf("%d", &valor);
				removeChave(L, valor);
			break;

			case 6:
				imprimir(L);
			break;

			case 7:
				printf("INFORME O ELEMENTO QUE DESEJA BUSCAR: ");
				scanf("%d", &valor);
				buscar(L, valor);
			break;

			case 0:
				printf("SAINDO..........\n");
			break;
		}
	}while(op != 0);

return 0;
}
