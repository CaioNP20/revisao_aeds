#include <stdio.h>
#include <stdlib.h>

struct termo {
    int coef;
    int grau;
};

typedef struct termo Termo;

//PROTOTIPOS
int compare(const void * a, const void * b);
void escanear (Termo * vet, int qtd);
void imprimir (Termo * vet, int qtd);

//MAIN
int main(void)
{
    /*int vet[] = {50, 20, 4, 76, 8};
    qsort(vet, 5, sizeof(vet[0]), compare);*/

    printf("Quantidade de termos: ");
    int qtd;
    scanf("%d", &qtd);

    Termo vet[qtd];
    escanear(vet, qtd);
    imprimir(vet, qtd);

    qsort(vet, qtd, sizeof(Termo), compare);
    imprimir(vet, qtd);
    
    return 0;
}

//FUNCOES
int compare(const void * a, const void * b)
{
    Termo *termoA = (Termo *) a;
    Termo *termoB = (Termo *) b;
    return (termoB->grau - termoA->grau);
}

void escanear (Termo * vet, int qtd)
{
    for (int i = 0; i < qtd; i++) {
        printf("\nTermo N%d\n", i + 1);
        printf("Coeficiente: ");
        scanf("%d", &vet[i].coef);
        printf("Grau: ");
        scanf("%d", &vet[i].grau);
    }
}

void imprimir (Termo * vet, int qtd)
{
    printf("Resultado: ");
    for (int i = 0; i < qtd; i++) {
        if (i != qtd - 1) {
            printf("%dx^%d + ", vet[i].coef, vet[i].grau);
        }
        else {
            printf("%dx^%d", vet[i].coef, vet[i].grau);
        }
    }
    printf("\n");
}