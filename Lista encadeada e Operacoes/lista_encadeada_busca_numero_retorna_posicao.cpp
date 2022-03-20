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
int busca_num(Lista * inicio, int numero_busca);
void imprime_lista(Lista * inicio);


/*
* Funcao main
*/
int main() {
    Lista *lista = NULL;
    int menu, numero_busca= 0;
    
    do{
	    system("cls");
	    printf("############################\n");
	    printf("########## MENU ############\n");
	    printf("1 - Inserir lista encadeada\n");
	    printf("2 - Buscar numero\n");
	    printf("3 - Imprime lista\n");
	    printf("4 - Sair\n");
	    
	    printf("Digite a opcao desejada: ");
	    scanf("%d",&menu);
	    
	    switch(menu){
	        case 1:
	            lista = insere_lista(lista);
	            break;
	        case 2:
	        	printf("Digite o numero buscado: ");
	        	scanf("%d",&numero_busca);
	            busca_num(lista,numero_busca);
	            break;
	        case 3:
	        	imprime_lista(lista);
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

int busca_num(Lista * inicio, int numero_busca){
	Lista * aux = inicio;
    int posicao = 0, achou = 0, i = 1;

	if(inicio == NULL){
	    printf("A lista esta vazia");
	} else{
	    while (aux->prox != NULL){
	    	
				if(aux->num != numero_busca){
					
				}else{
					posicao = i;
					achou = 1;
				}
				i++;
			    aux = aux->prox;
			    
			    if(aux->num == numero_busca){
					posicao = i;
					achou = 1;
				}
			    
	    }
	}
	
	if(achou == 0){
		printf("\nO numero nao esta na lista");
	}else{
		printf("\nA posicao do numero e: %d",posicao);
	}
	
	return posicao;
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