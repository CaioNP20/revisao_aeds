#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ESTRUTURAS
struct node{
	char n[5];
	struct node * prox;
};

typedef struct node no;

//PROTOTIPOS
int hash(char * nota);
no * busca(char * nota, no * vet, int index);
void inserir (char * nota, no * vet);
void imprimir (no * tabela, int tam);

//MAIN
int main(void)
{
	int len = 9;
	no tabela[len];
	no * aux;

	char nota[5];
	int op = 2;

	for (int i = 0; i < len; ++i) {
		tabela[i].prox = NULL;
	}

	for (int i = 0; i < 7; ++i) {
		printf("Nota que deseja inserir: ");
		scanf("%s", nota);
		inserir(nota, tabela);
	}

	for (int i = 0; i < len; ++i) {
		aux = tabela[i].prox;
		printf("HASH %d: ", i);
		while (aux != NULL) {
			printf("%s ---> ", aux -> n);
			aux = aux -> prox;
		}
		printf("\n\n");
	}

	for (int i = 0; i < len; ++i) free(tabela[i].prox);

	return 0;
}

//FUNCOES
int hash(char * nota)
{
	if (strcmp(nota, "DO") == 0) return 4;
	else if (strcmp(nota, "RE") == 0) return 1;
	else if (strcmp(nota, "MI") == 0) return 5;
	else if (strcmp(nota, "FA") == 0) return 4;
	else if (strcmp(nota, "SOL") == 0) return 4;
	else if (strcmp(nota, "LA") == 0) return 1;
	else return 8;
}

void inserir (char * nota, no * vet)
{
	int pos = hash(nota);
	no * aux = busca(nota, vet, pos);
	if (aux -> prox == NULL) {
		aux -> prox = malloc(sizeof(no));
		strcpy(aux -> prox-> n, nota);
		aux -> prox -> prox = NULL;
		printf("NOTA INSERIDA COM SUCESSO\n\n");
	}
	else {
		printf("Nota ja esta presente\n");
	}
}

no * busca(char * nota, no * vet, int index)
{
	no * endereco = &vet[index];
	while (endereco -> prox != NULL && strcmp(endereco -> prox -> n, nota) != 0) {
		endereco = endereco -> prox;
	}
	return endereco;
}

/*
	for (int i = 0; i < 7; ++i) {
		no * bloco = malloc(sizeof(no));
		scanf("%s", bloco -> n);
		aux -> prox = bloco;
		aux = bloco;
		bloco -> prox = NULL;
	}

	printf("\n");
	aux = tabela[0].prox;
	while (aux != NULL) {
		printf("%s\n", aux -> n);
		aux = aux -> prox;
	}
	*/

/*while (op != 0) {
		printf("\n\tMENU\n");
		printf("<1> - INSERIR\n");
		printf("<2> - IMPRIMIR\n");
		printf("<0> - SAIR\n\nO que deseja: ");
		scanf("%d", &op);

		switch (op)
		{
			case 1:
				printf("Qual nota deseja inserir: \n");
				scanf("%s", nota);
				inserir(nota, tabela);
				break;

			case 2:
				imprimir(tabela, len);
				break;

			default:
				break;
		}
	}*/