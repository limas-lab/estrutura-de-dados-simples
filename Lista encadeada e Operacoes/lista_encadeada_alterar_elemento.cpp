/*
Faça um programa contendo uma função para alterar um elemento na lista ligada ou encadeada
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


LISTA * altera_lista(LISTA * inicio){
	
    int numero, achou = 0, numero_troca;
	LISTA * aux;
	LISTA * anterior;
	
    printf("Informe um numero que deseja modificar: ");
	scanf("%d", &numero);
    printf("Trocar pra qual numero: ");
    scanf("%d", &numero_troca);
	
	if(inicio == NULL){
		printf("A lista está vazia");
        } 
    else{
		aux = inicio;
		anterior = inicio;
		
		while(aux != NULL){
            if(numero == aux->num){
                aux->num = numero_troca;
                achou = achou + 1;
			} else{
				anterior = aux;
				aux = aux->prox;
			}
		}
		
        if(achou == 0){
			printf("\nNumero não encontrado!");
            }
        else{
			printf("\nNumero alterado com sucesso!", achou);
            }
	}
	return inicio;
}


int main () {
	LISTA * inicio = NULL;
	int menu, elemento;

	do {
		system("cls");
		printf("\nMENU DE OPCOES");
		printf("\n1 - Inserir elementos na lista");
        printf("\n2 - Alterar elemento da lista");
		printf("\n3 - Imprimir lista");
		printf("\n4 - Sair");
		printf("\nOpcao:");
		scanf("%d", &menu);
		
		switch(menu) {
			case 1:
                inicio = insere_inicio(inicio);
				break;
			case 2:
				inicio = altera_lista(inicio);
				break;
			case 3:
				imprime_lista(inicio);
				break;
		}
		getch();
        
	} while (menu != 4);
}