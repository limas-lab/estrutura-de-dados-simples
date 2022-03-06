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
Lista * insere_fim(Lista * inicio);
void imprime_lista(Lista * inicio, int tipo);
Lista * retira(Lista * l);
Lista * retira_prefixo(Lista * l,int n);

/*
* Funcao main
*/
int main () {
	Lista * l = NULL;
    
	int menu;

	do {
		system("cls");
		printf("\nMENU DE OPCOES");
		printf("\n1 - Inserir lista");
        printf("\n2 - Retira prefixo");
        printf("\n3 - Imprimir listas");
        printf("\n4 - Sair");
		printf("\nOpcao:");
		scanf("%d", &menu);
		
		switch(menu) {
			case 1:
                l = insere_fim(l);
				break;
			case 2:
				l = retira(l);
				break;
			case 3:
                imprime_lista(l,1);
				break;
		}
        getch();
	} while (menu != 4);
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

Lista * retira(Lista * l){
    Lista * lista = l;
    int num = 0;

    do{
        printf("Insira o no que quer deletar: ");
        scanf("%d",&num);

        if(num<0){
            printf("Insira um valor POSITIVO!");
        }
    }while(num<0);
    
    lista = retira_prefixo(lista,num);
    return lista;
}

Lista * retira_prefixo(Lista * l,int n){
    Lista * aux = l;
    int num = n, j = 1;

    while(aux->prox != NULL){
        if(aux->prox != NULL){
            aux = aux->prox;
            j++;

            if(j == num){
                l = aux->prox;
                delete(aux);
                aux = l;
            }
        }
    }
    
    if(num >= j){
                l = NULL;
                aux = l;
            }

    return l;
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