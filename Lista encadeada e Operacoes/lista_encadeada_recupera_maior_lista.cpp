#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


struct Lista{
    double num;
    Lista *prox;
};

/*
* Declara escopo das funcoes
*/
Lista *insere_lista(Lista * inicio);
double maior_lista(Lista * inicio);
void imprime_lista(Lista * inicio);

/*
* Funcao main
*/
int main() {
    Lista *lista = NULL;
    int menu;
    double maior;
    
    do{
	    system("cls");
	    printf("############################\n");
	    printf("########## MENU ############\n");
	    printf("1 - Inserir lista encadeada\n");
	    printf("2 - Maior numero\n");
	    printf("3 - Imprimir maior\n");
	    printf("4 - Sair\n");
	    
	    printf("Digite a opcao desejada: ");
	    scanf("%d",&menu);
	    
	    switch(menu){
	        case 1:
	            lista = insere_lista(lista);
	            break;
	        case 2:
	            maior = maior_lista(lista);
	            break;
	        case 3:
	        	imprime_lista(lista);
				printf("\nO maior da lista eh: %.2lf\n",maior);
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
	scanf("%lf", &novo->num);

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

double maior_lista(Lista * inicio){
	Lista * aux = inicio;
    double maior = 0, atual = 0;

	if(inicio == NULL){
	    printf("A lista esta vazia");
	} else{
	    while (aux->prox != NULL){
	    	
				atual = aux->num;
				
				if(atual >= maior){
					maior = atual;
				}
				
			    aux = aux->prox;
			    
				if(aux->prox == NULL){
					
		    		atual = aux->num;
				
					if(atual >= maior){
						maior = atual;
					}
			}    
			
	    }
	}
	return maior;
}


void imprime_lista(Lista * inicio){
	if(inicio == NULL){
		printf("\nA lista esta vazia");
	} else{
		Lista * aux;
		printf("\nLista: ");
		aux = inicio;
		while(aux != NULL){
			printf(" %.2lf", aux->num);
			aux = aux->prox;
		}
	}
}