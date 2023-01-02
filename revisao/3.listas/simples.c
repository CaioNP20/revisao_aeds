//NAO POSSUI NO CABECA NEM RETAGUARDA, E ACEITA REPETICAO
#include <stdio.h>
#include <stdlib.h>

struct node {
    int n;
    struct node * prox;
};

typedef struct node no;

void imprimir(no * lista);
no * inserir(no * ret, int v);
//void deletar(no * cab, int v);
//no * busca(no * cab, int v);
void esvaziar(no * cab);

int main(void)
{
    no * cabeca;
    no * aux;

    int op = 7, num;
    char v = 'T';

    while (op != 0) {
        printf("\n\tMENU\n");
        printf("1 - INSERIR\n");
        //printf("2 - REMOVER\n");
        printf("3 - ESVAZIAR\n");
        printf("4 - IMPRIMIR\n");
        printf("0 - SAIR\n\nO que deseja: ");
    
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            if (v == 'T') {
                cabeca = malloc(sizeof(no));
                printf("Valor que deseja inseir: ");
                scanf("%d", &cabeca -> n);
                cabeca -> prox = NULL;
                aux = cabeca;
                printf("valor inserido com sucesso\n");
                v = 'F';
            }
            else {
                printf("Valor que deseja inseir: ");
                scanf("%d", &num);
                aux = inserir(aux, num);
                printf("VALOR INSERIDO COM SUCESSO\n");
            }
            break;

        case 3:
            free(cabeca);
            v = 'T';
            printf("LISTA ESVAZIADA\n");
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

no * inserir(no * ret, int v)
{
    no * bloco = malloc(sizeof(no));
    bloco -> n = v;
    bloco -> prox = NULL;
    ret -> prox = bloco;
    return bloco;
}

void imprimir(no * lista)
{
    printf("SITUACAO ATUAL DA LISTA:\n");
    while (lista != NULL) {
        printf("%d\n", lista -> n);
        lista = lista -> prox;
    }
}

no * busca(no * cab, int v)
{
    no * anterior;
    while (cab != NULL || cab -> n != v) {
        /* code */
    }
}