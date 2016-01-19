#include <stdio.h>

int BuscaBinaria(int v[], int chave, int inferior, int superior);

int main()
{
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int chave;
    int pos;

    printf("Escreva a chave: ");
    scanf("%d", &chave);

    pos = BuscaBinaria(vetor, chave, 0, 9);

    if (pos != -1)
    {
        printf("\nPosicao da chave: %d", pos);
    }

    return 0;
}

int BuscaBinaria(int v[], int chave, int inferior, int superior)
{
    int meio;

    meio = (inferior + superior) / 2;

    if (inferior > superior)
    {
        printf("Chave nao encontrada");
        return -1;
    }

    if (v[meio] == chave)
    {
        printf("Chave encontrada");
        return meio;
    }

    if (chave < v[meio])
    {
        return BuscaBinaria(v, chave, inferior, meio - 1);
    }

    return BuscaBinaria(v, chave, meio + 1, superior);
}
