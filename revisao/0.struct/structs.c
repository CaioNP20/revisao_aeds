#include <stdio.h>

struct aluno {
    char nome[50];
    float p1;
    float p2;
    char status;
};

//PROTOTIPOS
void imprime(struct aluno * vet, int qtd);
void escaneia(struct aluno * vet, int qtd);

//MAIN
int main(void)
{
    int qtd_alunos;
    printf("Quantidade de alunos: ");
    scanf("%d", &qtd_alunos);
    struct aluno alunos[qtd_alunos];

    for (int i = 0; i < qtd_alunos; i++) {
        printf("\nNome do aluno: ");
        getchar();
        fgets(alunos[i].nome, 49, stdin);
        printf("Nota P1: ");
        scanf("%f", &alunos[i].p1);
        printf("Nota P2: ");
        scanf("%f", &alunos[i].p2);
        if ((alunos[i].p1 + alunos[i].p2) / 2 >= 7) {
            alunos[i].status = 'A';
        }
        else if ((alunos[i].p1 + alunos[i].p2) / 2 < 3)  {
            alunos[i].status = 'R';
        }
        else {
            alunos[i].status = 'F';
        }
    }
    printf("\n------------------------\n\n");
    imprime(alunos, qtd_alunos);

    return 0;
}

//FUNCOES
void imprime(struct aluno * vet, int qtd)
{
    for (int i = 0; i < qtd; i++) {
        printf("Aluno: %s", vet[i].nome);
        printf("P1: %.2f\n", vet[i].p1);
        printf("P2: %.2f\n", vet[i].p2);
        printf("Status: %c\n\n", vet[i].status);
    }
}

void escaneia(struct aluno * vet, int qtd)
{
    
}