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
Lista * separa_lista(Lista * l);
Lista * separa(Lista * l, int n);

/*
* Funcao main
*/
int main () {
	Lista * l = NULL;
    Lista * split_m = NULL;

	int menu;

	do {
		system("cls");
		printf("\nMENU DE OPCOES");
		printf("\n1 - Inserir lista");
        printf("\n2 - Dividir lista");
        printf("\n3 - Imprimir listas");
        printf("\n4 - Sair");
		printf("\nOpcao:");
		scanf("%d", &menu);
		
		switch(menu) {
			case 1:
                l = insere_fim(l);
				break;
			case 2:
				split_m = separa_lista(l);
				break;
			case 3:
                imprime_lista(l,1);
                imprime_lista(split_m,2);
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

Lista * separa_lista(Lista * l){
    Lista * aux = NULL;
    Lista * valida = l;
    int n;

    if(valida == NULL){
        printf("A lista esta vazia");
    }else{
        printf("Insira o numero onde a lista sera dividida: ");
        scanf("%d",&n);
        aux = separa(valida,n);
    }
    return aux;
}

Lista * separa(Lista * l, int n){
    Lista * aux = l;
    Lista * nova = new Lista();

    int num = n;
    int find = 0;

        while(aux != NULL){
            if(num == aux->num){
                find = 1;
                break;
            }
            aux = aux->prox;
        }
        
        if(find != 0){
            aux = l;

            while(aux != NULL){
                if(aux->num != num){
                    aux = aux->prox;
                }else{
                    nova = aux->prox;
                    aux->prox = NULL;
                    break;
                }
            }
        }else{
            printf("O numero nao esta na lista");
        }

    return nova;
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