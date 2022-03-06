#include <stdio.h>
#include <iostream>
#include <conio.h>

struct LISTA{
	int num;
	LISTA * prox;
};

/*
* Declara escopo das funcoes
*/
LISTA * insere_fim(LISTA * inicio);
int * transforma(LISTA *inicio, int *vetor);
int tam_lista(LISTA * inicio);
void imprime_lista(LISTA * inicio);

/*
* Funcao main
*/
int main () {
	LISTA * inicio = NULL;
	int menu, i;
    int * vetor = NULL;
	int tam = 0;

	do {
		system("cls");
		printf("\nMENU DE OPCOES");
		printf("\n1 - Inserir lista");
        printf("\n2 - Transformar lista em vetor");
		printf("\n3 - Imprimir vetor");
        printf("\n4 - Imprimir lista");
        printf("\n5 - Sair");
		printf("\nOpcao:");
		scanf("%d", &menu);
		
		switch(menu) {
			case 1:
                inicio = insere_fim(inicio);
				break;
			case 2:   
				vetor = transforma(inicio, vetor);
				break;
			case 3:
			tam = tam_lista(inicio);
				printf("Vetor: ");
                    for(i=0;i<tam;i++){        
                        printf("%d ",vetor[i]);
                    }
				break;
            case 4:
				imprime_lista(inicio);
				break;
		}
		getch();
        
	} while (menu != 5);
}


/*
* Corpo das funcoes
*/

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


int * transforma(LISTA *inicio, int *vetor){
	//declaracao das variaveis
	LISTA * aux = inicio;
	int tam = 0, i = 0;

	tam = tam_lista(inicio);
	vetor = (int *) malloc(sizeof(int) * tam);

	while(aux != NULL){
			vetor[i] = aux->num;
			aux = aux->prox;
			i++;
	}
	return vetor;
}

int tam_lista(LISTA * inicio){
	LISTA * aux = inicio;
	int tam = 1;

	while(aux->prox != NULL){
		tam = tam + 1;
		aux = aux->prox;
	}
	return tam;
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