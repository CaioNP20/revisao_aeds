//FIRST IN, FIRST OUT
//Possui duas variaveis auxiliares, FRENTE e RETAGUARDA

#include <stdio.h>

//PROTOTIPOS
void esvazia(int *f, int *r); //Coloca as duas no inicio
char enfila(int fila[], int *r, int num, int tamanho, int *f);//RETORNA INT PARA ATT retaguarda
char desenfila(int fila[], int *f, int *r, int tamanho);//RETORNA INT PARA ATT frente
void imprimir(int fila[], int f, int r, int tamanho);

int main(void)
{
    int frente = -1, retaguarda = 0, tamanho;
    printf("Tamanho da fila: ");
    scanf("%d", &tamanho);

    int fila[tamanho], num, op = 7;

    char aux;

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
            aux = enfila(fila, &retaguarda, num, tamanho, &frente);
            if (aux != 'F') printf("NUMERO INSERIDO COM SUCESSO\n");
            else printf("FILA ESTA CHEIA!\n");
            break;

        case 2:
            aux = desenfila(fila, &frente, &retaguarda, tamanho);
            if (aux == 'F') printf("FILA ESTA VAZIA!\n");
            break;

        case 3:
            esvazia(&frente, &retaguarda);
            printf("FILA ESVAZIADA\n");
            break;

        case 4:
            if (frente != -1) imprimir(fila, frente, retaguarda, tamanho);
            else printf("FILA ESTA VAZIA!\n");
            break;
        
        default:
            break;
        }
    }
}

void esvazia(int *f, int *r)
{
    *f = -1;
    *r = 0;
}

char enfila(int fila[], int *r, int num, int tamanho, int *f)
{
    int pos = (*r % tamanho);
    if (pos != *f) {
        fila[pos] = num;
        if (*f == -1) *f = 0;
        *r = pos + 1;
        return 'T';
    }
    else return 'F';
}

char desenfila(int fila[], int *f, int *r, int tamanho)
{
    if (*f != -1) {
        int removido = fila[*f];
        if (*f == *r) esvazia(f, r);
        else *f = (*f % tamanho) + 1;
        printf("ELEMENTO REMOVIDO FOI: %d\n", removido);
        return 'T';
    }
    else return 'F';
}

void imprimir(int fila[], int f, int r, int tamanho)
{
    printf("SITUACAO ATUAL DA FILA:\n");
    
    for (; f % tamanho != r; ++f) {
        printf("%d\n", fila[f]);
    }
}

//Nao havia necessidade da variavel aux, no inicio ia usar return nas funcoes
//para atualizar as variaveis, mas acabei usando ponteiro