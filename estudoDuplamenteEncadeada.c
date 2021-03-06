#include<stdio.h>
#include<stdlib.h>

//criando a estrutura para uma lista duplamente encadeada
typedef struct no{
	int chave;
	struct no * prox;
	struct no * ant;
} No;

//função que cria uma lista vazia
No * criaLista(){
	return NULL;
}

//função que insere elemento no inicio da lista
No * insereInicio(No * lista, int ch){
	No * novo = (No *) calloc(1, sizeof(No)); //criando o novo elemento
	//encadeando o elemento
	novo->chave = ch; //preenchendo o campo de informação do elemento
	novo->prox = lista; //fazendo o elemento entrar no inicio da lista
	novo->ant = NULL; //a posição anterior ao elemento aponta para NULL
	//verificando se a lista nao esta vazia
	if(lista != NULL) lista->ant = novo;
	return novo;
}

//função para realizar a busca de um elemento na lista duplamente encadeada
No * busca(No * lista, int ch){
	No * aux;
	for(aux = lista; aux != NULL; aux = aux->prox){
		if(aux->chave == ch) return aux; //achou o elemento
	}return NULL; //nao achou o elemento
}

//função para imprimir os valores armazenados na lista duplamente encadeada
void imprimir(No *lista){
	No * aux;
	for(aux = lista; aux != NULL; aux = aux->prox){ //percorrendo a lista
		printf(" %d ", aux->chave); //imprimindo os elementos
	}
}

//função para remover um elemento na lista
//essa função faz o uso da funçção de busca anteriormente implementada
No * removerElemento(No * lista, int ch){
	No * aux;
	aux = busca(lista, ch);
	if(aux == NULL) return lista; //caso base
	//retira o elemento do encadeamento
	if(lista == aux){//testa se é o priemeiro elemento
		lista = aux->prox;
	}else{
		aux->ant->prox = aux->prox;
	}if(aux->prox != NULL){ //testa se e o ultimo elemento
		aux->prox->ant = aux->ant;
	}free(aux);
return lista;
}

int main(void){

	No * lista = criaLista();

	int op, valor;

	do{
		printf("\n1- inserir um elemento\n2- remover elemento\n3- imprimir\n4- buscar elemento\n0- sair "); scanf("%d", &op);

		switch(op){
			case 1:
				printf("\nentre com o elemento a ser inserido: "); scanf("%d", &valor);
				lista = insereInicio(lista, valor);
			break;

			case 2:
				printf("\nentre com o elemento a ser removido: "); scanf("%d", &valor);
				lista = removerElemento(lista, valor);
			break;

			case 3:
				imprimir(lista);
			break;

			case 4:
				printf("\nentre com o elemento para busca: "); scanf("%d", &valor);
				busca(lista, valor);
			break;
		}
	}while(op != 0);
}
