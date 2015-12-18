#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void BubbleSort(int v[], int n);          // Função que ordena com bubble sort e mostra o passo a passo
void Troca(int *n1, int *n2);             // Função para trocar elementos no vetor
void ImprimeVetor(int v[], int n, int j); // Funação para imprimir o vetor com demonstração passo a passo

int main(void)
{
    int vetor[10] = {8, 2, 9, 7, 4, 3, 10, 6, 1, 5};
    int tam = 10;

    // Chama a função para ordenar o vetor por Bubble Sort
    BubbleSort(vetor, tam);

    printf("\n");
    system("pause");
    return 0;
}

// Executa o algoritmo do Bubble Sort, mostrando passo a passo os eventos
void BubbleSort(int v[], int n)
{
    int i, j;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            ImprimeVetor(v, n, j);
            printf("\n\n\n\n %d eh maior do que %d? ", v[j], v[j + 1]);
            getch();

            if (v[j] > v[j + 1])
            {
                printf("\n\n Sim, entao trocar a posicao dos elementos");
                Troca(&v[j], &v[j + 1]);
            }
            else
            {
                printf("\n\n Nao, entao manter a posicao dos elementos");
            }
            getch();
        }

        ImprimeVetor(v, n, j);
        printf("\n\n\n\n Posicao %d do vetor foi ordenada.\n", j);
        printf(" Executar novamente o processo sem contar a posicao %d em diante.", j);
        getch();
    }

    ImprimeVetor(v, n, -1);
    printf("\n\n\n\n O vetor foi ordenado com sucesso!");
    getch();
}

// Troca os elementos requisitados
void Troca(int *n1, int *n2)
{
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

// Imprime na tela o vetor e o que esta sendo realizado
void ImprimeVetor(int v[], int n, int j)
{
    int i;

    system("cls");
    printf("\n Ordenacao por BubbleSort -- Pressione ENTER para ver passo a passo\n\n\n\n");
    printf(" Elementos do vetor:");
    printf("\n\n");

    for (i = 0; i < n; i++)
    {
        if ((j == i || j + 1 == i) && j != -1) // Imprime o elemento que estiver sendo comparado entre chaves
            printf(" {%d} ", v[i]);
        else
            printf("  %d  ", v[i]); // Imprime o restante dos elementos normalmente
    }
}
