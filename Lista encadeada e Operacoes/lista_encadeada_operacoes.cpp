/*
Faça um programa contendo as seguintes operações referentes à lista ligada: criar
lista, inserir elemento no início da lista, inserir elemento no fim da lista, remover
item da lista, buscar elemento na lista e imprimir lista. 
*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>


struct LISTA{
	int num;
	LISTA * prox;
};


LISTA * insere_inicio(LISTA * inicio){
	LISTA * novo = new LISTA();	
	printf("Informe um numero:");
	scanf("%d", &novo->num);
	
	if(inicio == NULL){ //Cria primeiro registro
		inicio = novo;
		inicio->prox=NULL;
	} else{ //insere no inicio
		novo->prox = inicio;
		inicio = novo;
	}
	return inicio;
}

LISTA * insere_fim(LISTA * inicio) {
	LISTA * aux;
	LISTA * novo = new LISTA();
	printf("Informe um numero:");
	scanf("%d", & novo->num);
	if (inicio == NULL) { // se a lista for vazia
		inicio = novo;
		inicio->prox=NULL;
	} else {
		aux = inicio;
		while (aux -> prox != NULL) {
			aux = aux->prox;
		}
		aux-> prox = novo;
		novo->prox = NULL;
	}
	return inicio;
}

LISTA * remove_lista(LISTA * inicio){
	int numero, achou = 0;
	LISTA * aux;
	LISTA * anterior;
	printf("Informe um numero que deseja remover:");
	scanf("%d", &numero);
	
	if(inicio == NULL){
		printf("A lista está vazia");
	} else {
		aux = inicio;
		anterior = inicio;
		
		while(aux != NULL){
			if(numero == aux->num){
				if(aux == inicio){
					inicio = aux->prox;
					delete(aux);
					aux = inicio;
				} else{
					anterior->prox = aux->prox;
					delete(aux);
					aux = anterior->prox;
				}
				achou = achou + 1;
			} else{
				anterior = aux;
				aux = aux->prox;
			}
		}
		if(achou == 0){
			printf("\nNumero não encontrado!");
		} else{
			printf("\nNumero removido com sucesso %d vezes", achou);
		}
	}
	return inicio;
}

void imprime_lista(LISTA * inicio){
	if(inicio == NULL){
		printf("\nA lista está vazia");
	} else{
		LISTA * aux;
		printf("\nLista: ");
		aux = inicio;
		while(aux != NULL){
			printf(" %d", aux->num);
			aux = aux->prox;
		}
	}
}

void busca_lista(LISTA*inicio, int elemento){
	int achou = 0;
	
	if(inicio == NULL){
		printf("\nA lista esta vazia!");
	} else{
		LISTA * aux;
		printf("\nLista: ");
		aux = inicio;
		while( aux != NULL){
			if(elemento == aux->num){
				achou = 1;
				break;
			}
			aux = aux->prox;
		}
	}
	if(achou == 1){
		printf("O numero esta na lista!");
	} else{
		printf("O elemento não esta na lista!");
	}
}

int main () {
	LISTA * inicio = NULL;
	int menu, elemento;
	do {
		system("cls");
		printf("\nMENU DE OPCOES");
		printf("\n1 - Inserir no inicio da lista");
		printf("\n2 - Inserir no final da lista");
		printf("\n3 - Remover item da lista");
		printf("\n4 - Buscar item da lista");
		printf("\n5 - Consultar os itens da lista");
		printf("\n6 - Sair");
		printf("\nOpcao:");
		scanf("%d", &menu);
		
		switch(menu) {
			case 1:
				inicio = insere_inicio(inicio);
				break;
			case 2:
				inicio = insere_fim(inicio);
				break;
			case 3:
				inicio = remove_lista(inicio);
				break;
			case 4:
				printf("Informe o elemento que deseja buscar:");
				scanf("%d", &elemento);
				busca_lista(inicio, elemento);
				break;
			case 5:
				imprime_lista(inicio);
				break;
		}
		getch();
	} while (menu != 6);
}