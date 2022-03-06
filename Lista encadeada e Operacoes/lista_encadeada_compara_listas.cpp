#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct LISTA{
	int num;
	LISTA * prox;
};

/*
* Declara escopo das funcoes
*/
LISTA * insere_fim(LISTA * inicio);
void compara_listas(LISTA * um, LISTA * dois);
int tam_lista(LISTA * inicio);
void imprime_lista(LISTA * inicio);

/*
* Funcao main
*/
int main () {
	LISTA * um = NULL;
    LISTA * dois = NULL;
	int menu;

	do {
		system("cls");
		printf("\nMENU DE OPCOES");
		printf("\n1 - Inserir lista um");
        printf("\n2 - Inserir lista dois");
		printf("\n3 - Comparar as duas litas");
        printf("\n4 - Imprimir listas");
        printf("\n5 - Sair");
		printf("\nOpcao:");
		scanf("%d", &menu);
		
		switch(menu) {
			case 1:
                um = insere_fim(um);
				break;
			case 2:   
				dois = insere_fim(dois);;
				break;
			case 3:
                compara_listas(um, dois);
				break;
            case 4:
				imprime_lista(um);
                imprime_lista(dois);
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


void compara_listas(LISTA * um, LISTA * dois){

    if(um == NULL || dois ==NULL){
        printf("\nA lista está vazia");
    }else{

        int tam_um = 0, tam_dois = 0;

        tam_um = tam_lista(um);
        tam_dois = tam_lista(dois);

        if(tam_um != tam_dois){
            printf("\nAs duas listas tem tamanhos diferentes!\n");
        }else{
            LISTA * aux_um = um;
            LISTA * aux_dois = dois;
            int * compara = NULL;
            int i = 0;
          
            compara = (int *) malloc(sizeof(int) * tam_um);

            while(aux_um != NULL && aux_dois != NULL){
                if(aux_um->num == aux_dois->num){
                    compara[i] = 1;
                }else{
                    compara[i] = 0;
                }
                aux_um = aux_um->prox;
                aux_dois = aux_dois->prox;
                i++;
            }

            for(i=0;i<tam_um;i++){
                if(compara[i] != 1){
                    printf("\nAs duas listas tem o mesmo tamanho mas conteudos diferentes");
                    break;
                }else if(i == tam_um-1 && compara[i] == 1){
                    printf("\nAs duas listas tem o mesmo tamanho e conteudos iguais");
                    break;
                }
            }
        }
    }
}


int tam_lista(LISTA * inicio){
    int tam = 1;

    if(inicio == NULL){
        printf("\nA lista está vazia");
    }else{
        LISTA * aux = inicio;
        
        while(aux->prox != NULL){
            tam = tam + 1;
            aux = aux->prox;
        }
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