#include <stdio.h>
#include <stdlib.h>

struct node {
    int n;
    struct node * prox;
};

typedef struct node no;

void esvaziar(no * top);
void imprimir(no * lista);
no * inserir(no * ant);
no * deletar(no * top);

int main(void)
{
    no * topo; 
    no * aux;

    char v = 'T';

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
            if (v == 'T') {
                topo = malloc(sizeof(no));
                printf("Numero que deseja inserir: ");
                scanf("%d", &topo -> n);
                topo -> prox = NULL;
                v = 'F';
                printf("ELEMENTO INSERIDO COM SUCESSO\n");
            }
            else {
                topo = inserir(topo);
            }
            break;

        case 2:
            topo = deletar(topo);
            break;

        case 3:
            esvaziar(topo);
            v = 'T';
            break;

        case 4:
            imprimir(topo);
            break;
        
        default:
            break;
        }
    }

    free(topo);

    return 0;
}

no * inserir(no * ant)
{
    printf("Valor que deseja inserir: ");
    no * bloco = malloc(sizeof(no));
    scanf("%d", &bloco -> n);
    bloco -> prox = ant;
    printf("ELEMENTO INSERIDO COM SUCESSO!\n");
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

no * deletar(no * top)
{
    no * del = top;
    top = top -> prox;
    printf("ELEMENTO REMOVIDO: %d\n", del -> n);
    free(del);
    return top;
}

void esvaziar(no * top)
{
    free(top);
}