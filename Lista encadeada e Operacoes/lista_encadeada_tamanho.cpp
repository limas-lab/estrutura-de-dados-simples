/*
Faça  um  programa  contendo  uma  função  para  retornar  o  tamanho  de  uma  lista ligada
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


void tamanho_lista(LISTA * inicio){
	if(inicio == NULL){
		printf("\nA lista está vazia");
	} else{
		int cont = 0;
        LISTA * aux;
		aux = inicio;
        
		while(aux != NULL){
			cont = cont + 1;
			aux = aux->prox;
		}
        printf("\nTamanho lista: %d", cont);
	}
}



int main () {
	LISTA * inicio = NULL;
	int menu, elemento;
	do {
		system("cls");
		printf("\nMENU DE OPCOES");
		printf("\n1 - Consultar o tamanho da lista");
		printf("\n2 - Inserir elementos na lista");
		printf("\n3 - Sair");
		printf("\nOpcao:");
		scanf("%d", &menu);
		
		switch(menu) {
			case 1:
                tamanho_lista(inicio);
				break;
			case 2:
				inicio = insere_inicio(inicio);
				break;
		}
		getch();
	} while (menu != 3);
}