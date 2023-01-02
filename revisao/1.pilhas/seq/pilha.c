//last in, first out
//Variavel auxiliar -> topo | INSERCAO e DELECAO ocorrem nessa variavel
#include <stdio.h>

//PROTOTIPOS
int esvazia(int topo); //"Remocao" de todos os elementos
int push(int pilha[], int elemento, int topo); //Insercao ---- RETORNA INT PARA ATT VARIAVEL TOPO;
int pop (int topo); //"Remover" ---- RETORNA INT PARA ATT VARIAVEL TOPO;
void imprimir(int pilha[], int topo);

int main(void)
{
    int tamanho;
    printf("Tamanho da pilha: ");
    scanf("%d", &tamanho);

    int pilha[tamanho], topo = 0;

    int op = 7;

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
            if (topo == tamanho) printf("PILHA ESTA CHEIA\n");
            else {
                int num;
                printf("Numero a ser inserido: ");
                scanf("%d", &num);
                topo = push(pilha, num, topo);
                printf("NUMERO INSERIDO COM SUCESSO\n");
            }
            break;

        case 2:
            if (topo == 0) printf("PILHA ESTA VAZIA\n");
            else {
                printf("ELEMENTO REMOVIDO: %d\n", pilha[topo - 1]);
                topo = pop(topo);
            }
            break;

        case 3:
            topo = esvazia(topo);
            printf("LISTA ESVAZIADA\n");
            break;
        
        case 4:
            if (topo == 0) printf("PILHA ESTA VAZIA\n");
            else imprimir(pilha, topo);
            break;

        case 0:
            printf("OBRIGADO E VOLTE SEMPRE!\n");
            break;

        default:
            printf("POR FAVOR, INSIRA UMA OPCAO VALIDA\n");
            break;
        }
    }
}

int esvazia(int topo)
{
    return 0;
}

int push(int pilha[], int elemento, int topo)
{
    pilha[topo] = elemento;
    return topo + 1;
}

int pop (int topo)
{
    return topo - 1;
}

void imprimir(int pilha[], int topo)
{
    --topo;
    printf("SITUACAO ATUAL DA PILHA:\n");
    for ( ; topo >= 0; --topo) printf("%d\n", pilha[topo]);
}