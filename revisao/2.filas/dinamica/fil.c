#include <stdio.h>
#include <stdlib.h>

struct node {
    int n;
    struct node * prox;
};

typedef struct node no;

void esvaziar(no * f, no * r);
void imprimir(no * lista);
no * inserir(no * ret, int v);
no * deletar(no * f);

int main(void)
{
    no * frente = NULL;
    no * retaguarda;

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
            printf("Numero a ser inserido: ");
            scanf("%d", &num);
            if (frente == NULL) {
                frente = malloc(sizeof(no));
                frente -> n = num;
                frente -> prox = NULL;
                retaguarda = frente;
            }
            else {
                retaguarda = inserir(retaguarda, num);
            }
            break;

        case 2:
            if (frente != NULL) frente = deletar(frente);
            else printf("LISTA ESTA VAZIA\n");
            break;

        case 3:
            esvaziar(frente, retaguarda);
            frente = NULL;
            retaguarda = frente;
            break;

        case 4:
            if (frente != NULL) imprimir(frente);
            else printf("LISTA ESTA VAZIA\n");
            break;
        
        default:
            break;
        }
    }

    free(frente);

    return 0;
}

void esvaziar(no * f, no * r)
{
    free(f);
    free(r);
    printf("LISTA ESVAZIADA\n");
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

no * deletar(no * f)
{
    printf("ELEMENTO REMOVIDO: %d\n", f -> n);
    no * attf = f -> prox;
    free(f);
    return attf;
}