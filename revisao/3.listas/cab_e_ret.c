//POSSUI NO CABECA, NAO POSSUI RETAGUARDA, E NAO ACEITA REPETICAO
#include <stdio.h>
#include <stdlib.h>

struct node {
    int n;
    struct node * prox;
};

typedef struct node no;

void imprimir(no * lista);
void inserir(no * cab, int v);
void deletar(no * cab, int v);
no * busca(no * cab, int v);
void esvaziar(no * cab, no * ret);

int main(void)
{
    no * cabeca = malloc(sizeof(no));
    no * retaguarda = malloc(sizeof(no));
    cabeca -> prox = retaguarda;
    retaguarda -> prox = retaguarda;
    //no * aux;

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
            inserir(cabeca, num);
            break;

        case 2:
            printf("Numero que deseja remover: ");
            scanf("%d", &num);
            deletar(cabeca, num);
            break;

        case 3:
            if (cabeca -> prox == retaguarda) printf("LISTA ESTA VAZIA\n");
            else esvaziar(cabeca, retaguarda);
            break;

        case 4:
            if (cabeca -> prox == retaguarda) printf("LISTA ESTA VAZIA\n");
            else imprimir(cabeca -> prox);
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
    while (lista != lista -> prox) {
        printf("%d\n", lista -> n);
        lista = lista -> prox;
    }
}

no * busca(no * cab, int v)
{
    no * ant = cab;
    cab = cab -> prox;
    while (cab != cab -> prox) {
        if (cab -> n == v) return ant;
        else {
            ant = cab;
            cab = cab -> prox;
        }
    }
    return ant;
}

void inserir(no * cab, int v)
{
    no * aux = busca(cab, v);
    if (aux -> prox -> prox == aux -> prox) {
        no * bloco = malloc(sizeof(no));
        bloco -> n = v;
        bloco -> prox = aux -> prox;
        aux -> prox = bloco;
        printf("ELEMENTO ADICIONADO COM SUCESSO\n");
    }
    else printf("ELEMENTO JA PERTENCE A LISTA\n");
}

void deletar(no * cab, int v)
{
    no * aux = busca(cab, v);
    if (aux -> prox -> prox != aux -> prox) {
        no * del = aux -> prox;
        aux -> prox = del -> prox;
        free(del);
        printf("ELEMENTO REMOVIDO COM SUCESSO\n");
    }
    else printf("ELEMENTO NAO PERTENCE A LISTA\n");
}

void esvaziar(no * cab, no * ret)
{
    free(cab);
    free(ret);
    cab = malloc(sizeof(no));
    ret = malloc(sizeof(no));
    cab -> prox = ret;
    ret -> prox = ret;
    printf("LISTA ESVAZIADA\n");
}