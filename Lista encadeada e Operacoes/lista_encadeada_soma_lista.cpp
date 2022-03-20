#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


struct Lista{
    int num;
    Lista *prox;
};

/*
* Declara escopo das funcoes
*/
Lista *insere_lista(Lista * inicio);
int soma_lista(Lista * inicio);
void imprime_lista(Lista * inicio);

/*
* Funcao main
*/
int main() {
    Lista *lista = NULL;
    int menu, soma = 0;
    
    do{
	    system("cls");
	    printf("############################\n");
	    printf("########## MENU ############\n");
	    printf("1 - Inserir lista encadeada\n");
	    printf("2 - Somar lista\n");
	    printf("3 - Imprimir lista e soma\n");
	    printf("4 - Sair\n");
	    
	    printf("Digite a opcao desejada: ");
	    scanf("%d",&menu);
	    
	    switch(menu){
	        case 1:
	            lista = insere_lista(lista);
	            break;
	        case 2:
	            soma = soma_lista(lista);
	            break;
	        case 3:
				imprime_lista(lista);
	            printf("\nA soma da lista eh: %d\n",soma);
	            break;
	        }
	    getch();
	}while(menu != 4);
    
}

/*
* Corpo das funcoes
*/

Lista *insere_lista(Lista * inicio){
	Lista * aux;
	Lista * novo = new Lista();

	printf("Informe um numero: ");
	scanf("%d", &novo->num);

	if(inicio == NULL){
	    inicio = novo;
	    inicio->prox = NULL;
	} else{
	    aux = inicio;
	    while (aux->prox != NULL){
		    aux = aux->prox;
	    }
	    aux->prox = novo;
	    novo->prox = NULL;
	}
	return inicio;
}

int soma_lista(Lista * inicio){
	Lista * aux = inicio;
    int soma = 0;

	if(inicio == NULL){
	    printf("A lista esta vazia");
	} else{
	    while (aux->prox != NULL){
	    	
				soma = aux->num + soma;
			    aux = aux->prox;
			
			if(aux->prox == NULL){
		    	soma = aux->num + soma;
			}

	    }
	}
	return soma;
}


void imprime_lista(Lista * inicio){
	if(inicio == NULL){
		printf("\nA lista esta vazia");
	} else{
		Lista * aux;
		printf("\nLista: ");
		aux = inicio;
		while(aux != NULL){
			printf(" %d", aux->num);
			aux = aux->prox;
		}
	}
}
