/*
Escreva uma função que copie o conteúdo de um vetor para uma lista encadeada preservando a ordem dos elementos.
*/

#include <stdio.h>
#include <iostream>
#include <conio.h>

const int vt = 6;

struct LISTA{
	int num;
	LISTA * prox;
};

LISTA * insere_fim(LISTA * inicio, int vlVetor) {
	LISTA * aux;
	LISTA * novo = new LISTA();

	novo->num = vlVetor;
	
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

int main () {
	LISTA * inicio = NULL;
	int menu;
    int vetor[vt] = {NULL};

	do {
		system("cls");
		printf("\nMENU DE OPCOES");
		printf("\n1 - Inserir vetor");
        printf("\n2 - Transformar vetor em lista");
		printf("\n3 - Imprimir vetor");
        printf("\n4 - Imprimir lista");
		printf("\n5 - Sair");
		printf("\nOpcao:");
		scanf("%d", &menu);
		
		switch(menu) {
			case 1:
                int i;
                printf("Insira os valores do vetor de %d posicoes:",vt);

                for(i=0;i<vt;i++){
                    scanf("%d", &vetor[i]);
                    }                
				break;
			case 2:
                for(i=0;i<vt;i++){    
                    inicio = insere_fim(inicio, vetor[i]);
                }
				break;
			case 3:
				printf("Vetor: ");
                    for(i=0;i<vt;i++){        
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