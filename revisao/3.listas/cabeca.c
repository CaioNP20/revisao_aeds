//POSSUI NO CABECA, NAO POSSUI RETAGUARDA, E NAO ACEITA REPETICAO
#include <stdio.h>
#include <stdlib.h>

struct node {
    int n;
    struct node * prox;
};

typedef struct node no;

void imprimir(no * lista);
no * inserir(no * ret, int v);
void deletar(no * cab);
no * busca(no * cab, int v);
void esvaziar(no * cab);

int main(void)
{
    no * cabeca = malloc(sizeof(no));
    cabeca -> prox = NULL;
    no * aux;

    int op = 7, num;

    while (op != 0) {
        printf("\n\tMENU\n");
        printf("1 - INSERIR\n");
        printf("2 - REMOVER\n");
        printf("3 - ESVAZIAR\n");
        printf("4 - IMPRIMIR\n");
        printf("0 - SAIR\n\nO que deseja: ");
    
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Numero que deseja inserir: ");
            scanf("%d", &num);
            aux = busca(cabeca, num);
            if (aux -> prox == NULL) {
                inserir(aux, num);
                printf("NUMERO INSERIDO COM SUCESSO\n");
            }
            else {
                printf("NUMERO JA PERTENCE A LISTA\n");
            }
            break;

        case 2:
            printf("Numero que deseja remover: ");
            scanf("%d", &num);
            aux = busca(cabeca, num);
            if (aux -> prox != NULL) {
                deletar(aux);
                printf("NUMERO REMOVIDO COM SUCESSO\n");
            }
            else {
                printf("NUMERO NAO PERTENCE A LISTA\n");
            }
            break;

        case 3:
            esvaziar(cabeca);
            printf("LISTA ESVAZIADA\n");
            aux = cabeca;
            break;

        case 4:
            imprimir(cabeca -> prox);
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

no * inserir(no * ret, int v)
{
    no * bloco = malloc(sizeof(no));
    bloco -> n = v;
    bloco -> prox = NULL;
    ret -> prox = bloco;
    return bloco;
}

no * busca(no * cab, int v)
{
    no * ant = cab;
    cab = cab -> prox;
    while (cab != NULL) {
        if (cab -> n == v) return ant;
        else {
            ant = cab;
            cab = cab -> prox;
        }
    }
    return ant;
}

void esvaziar(no * cab)
{
    free(cab);
    cab = malloc(sizeof(no));
    cab -> prox = NULL;
}

void deletar(no * cab)
{
    no * del = cab -> prox;
    cab -> prox = del -> prox;
    free(del);
}