//ACEITA REPETICAO, sem uso do no cabeca ou retaguarda;

#include <stdio.h>
#include <stdlib.h>

struct node {
    int n;
    struct node * prox;
};

typedef struct node no;

void imprimir(no * lista);
void inserir(no * aux, int count);
void deletar(no * cab, int v);
no * busca(no * cab, int v);
void esvaziar(no * cab, no * ret);

int main(void)
{
    no * cabeca, * aux;

    char v = 'T';

    int op = 7, num, qtd;

    while (op != 0) {
        printf("\n\tMENU\n");
        printf("1 - INSERIR\n");
        //printf("2 - REMOVER\n");
        //printf("3 - ESVAZIAR\n");
        printf("4 - IMPRIMIR\n");
        printf("0 - SAIR\n\nO que deseja: ");
    
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Quantos numeros deseja inserir: ");
            scanf("%d", &qtd);
            if (v == 'T') {
                cabeca = malloc(sizeof(no));
                aux = cabeca;
                for (int i = 0; i < qtd; i++) {
                    printf("Numero: ");
                    scanf("%d", &aux -> n);
                    if (i != qtd - 1) {
                        aux -> prox = malloc(sizeof(no));
                        aux = aux -> prox;
                    }
                    else {
                        aux -> prox = NULL;
                    }
                }
                v = 'F';
                printf("PRIMEIROS ELEMENTOS ADICIONADOS COM SUCESSO\n");
            }
            else {
                inserir(aux, qtd);
                printf("NOVOS ELEMENTOS ADICIONADOS COM SUCESSO\n");
            }
            break;

        case 2:
            
            break;

        case 3:
            
            break;

        case 4:
            imprimir(cabeca);
            break;
        
        default:
            break;
        }
    }

    free(cabeca);

    return 0;
}

void imprimir(no * lista)
{
    printf("SITUACAO ATUAL DA LISTA:\n");
    while (lista != NULL) {
        printf("%d\n", lista -> n);
        lista = lista -> prox;
    }
}

void inserir(no * aux, int count)
{
    no * bloco = malloc(sizeof(no));
    for (int i = 0; i < count; i++) {
        printf("Numero: ");
        scanf("%d", &bloco -> n);
        if (i == 0) {
            if (count != 1) {
                aux -> prox = bloco;
                bloco -> prox = malloc(sizeof(no));
                bloco = bloco -> prox;
            }
            else {
                aux -> prox = bloco;
                bloco -> prox = NULL;
            }
        }
        else if (i != count - 1) {
                bloco -> prox = malloc(sizeof(no));
                bloco = bloco -> prox;
        }
        else {
            bloco -> prox = NULL;
        }
    }
}