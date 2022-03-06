#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Lista{
	int num;
	Lista * prox;
};

/*
* Declara escopo das funcoes
*/
void imprime_lista(Lista * inicio, int tipo);
Lista * insere_fim(Lista * inicio);
Lista * concatena(Lista * l1,Lista * l2);
Lista * copia_item(Lista * l3, int num);

/*
* Funcao main
*/
int main () {
	Lista * l1 = NULL;
    Lista * l2 = NULL;
    Lista * l3 = NULL;

	int menu;

	do {
		system("cls");
		printf("\nMENU DE OPCOES");
		printf("\n1 - Inserir lista 1");
        printf("\n2 - Inserir lista 2");
        printf("\n3 - Concatena listas");
        printf("\n4 - Imprimir listas");
        printf("\n5 - Sair");
		printf("\nOpcao:");
		scanf("%d", &menu);
		
		switch(menu) {
			case 1:
                l1 = insere_fim(l1);
				break;
			case 2:
				l2 = insere_fim(l2);
				break;
			case 3:
                l3 = concatena(l1,l2);
				break;
			case 4:
                imprime_lista(l1,1);
                imprime_lista(l2,2);
                imprime_lista(l3,3);
				break;
		}
        getch();
	} while (menu != 5);
}

/*
* Corpo das funcoes
*/

Lista * insere_fim(Lista * inicio) {
	Lista * aux;
	Lista * novo = new Lista();

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

Lista * copia_item(Lista * l3, int num){
    Lista * aux;
	Lista * novo = new Lista();
    int num_novo = num;

        novo->num = num_novo;

        if (l3 == NULL) {
            l3 = novo;
            l3->prox=NULL;
        } else {
            aux = l3;
            while (aux -> prox != NULL) {
                aux = aux->prox;
            }
            aux-> prox = novo;
            novo->prox = NULL;
        }
	return l3;
}


Lista * concatena(Lista * l1,Lista * l2){
    
        Lista * aux1 = l1;//percorrer lista 1
        Lista * aux2 = l2;//percorrer lista 2
        Lista * l3 = NULL;
        int num_aux;

        if (l1 == NULL && l2 == NULL) {
            printf("A duas listas estao vazias");
        }else if (l1 == NULL) {
            printf("A lista um esta vazia");
        }else if (l2 == NULL) {
            printf("A lista dois esta vazia");
        }else{
            while(aux1->prox != NULL){
                    num_aux = aux1->num;
                    l3 = copia_item(l3,num_aux);
                    aux1 = aux1->prox;

                    if(aux1->prox == NULL){
                        num_aux = aux1->num;
                        l3 = copia_item(l3,num_aux);
                    }
            }

            while(aux2->prox != NULL){
                    num_aux = aux2->num;
                    l3 = copia_item(l3,num_aux);
                    aux2 = aux2->prox;

                    if(aux2->prox == NULL){
                        num_aux = aux2->num;
                        l3 = copia_item(l3,num_aux);
                    }
            }

        }
        return l3;
}


void imprime_lista(Lista * inicio, int tipo){
	int num_lista = tipo;
    
    if(inicio == NULL){
		printf("\nA lista esta vazia");
	} else{
		Lista * aux;
		printf("\nLista %d: ",num_lista);
		aux = inicio;
		while(aux != NULL){
			printf(" %d", aux->num);
			aux = aux->prox;
		}
	}
}