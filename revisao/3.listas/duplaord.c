//POSSUI NO CABECA, NAO POSSUI RETAGUARDA, E NAO ACEITA REPETICAO
#include <stdio.h>
#include <stdlib.h>

struct node {
    int n;
    struct node * prox;
    struct node * ant;
};

typedef struct node no;

no * esvaziar(no * cab);
no * busca(int v, no * atual);
void inserir(no * cab, int v);
void deletar(no * cab, int v);
void imprimir(no * lista);

int main(void)
{
    no * cabeca = malloc(sizeof(no));
    cabeca -> prox = cabeca;
    cabeca -> ant = cabeca;

    int op = 7, num;

    while (op != 0) {
        printf("\n\tMENU\n");
        printf("1 - INSERIR\n");
        printf("2 - REMOVER\n");
        //printf("3 - ESVAZIAR\n");
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

        /*case 3:
            
            break;*/

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
    no * cabeca = lista;
    lista = lista -> prox;
    printf("SITUACAO ATUAL DA LISTA:\n");
    while (lista != cabeca) {
        printf("%d\n", lista -> n);
        lista = lista -> prox;
    }
}

no * busca(int v, no * atual)
{
    no * cabeca = atual;
    cabeca -> n = v;
    atual = atual -> prox;
    while (atual -> n < v) {
        atual = atual -> prox;
    }
    return atual;
}

void inserir(no * cab, int v)
{
    no * aux = busca(v, cab);
    if (aux -> n == v && aux != cab) printf("ELEMENTO JA PERTENCE A LISTA\n");
    else {
        no * bloco = malloc(sizeof(no));
        bloco -> n = v;
        bloco -> prox = aux;
        bloco -> ant = aux -> ant;
        aux -> ant -> prox = bloco;
        aux -> ant = bloco;
        printf("NUMERO INSERIDO!\n");
    }
}

void deletar(no * cab, int v)
{
    no * aux = busca(v, cab);
    if (aux == cab && aux -> ant -> n != v) printf("ELEMENTO NAO PERTENCE A LISTA\n");
    else {
        no * del = aux;
        aux -> ant -> prox = del -> prox;
        aux -> prox -> ant = del -> ant;
        free(del);
        printf("NUMERO REMOVIDO!\n");
    }
}