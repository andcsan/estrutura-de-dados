#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void BubbleSort(int v[], int n);
void SelectionSort(int v[], int n);
void InsertionSort(int v[], int n);
void Troca(int *n1, int *n2);
void ImprimeVetor(int v[], int n);

int main(void)
{
    int vetor[10] = {75, 86, 92, 63, 44, 32, 19, 28, 57, 20};
    int tam = 10;
    int selecao;

    printf("\n Vetor nao ordenado: \n");
    ImprimeVetor(vetor, tam);

    printf("\n\n\n Escolha o metodo de ordenacao: \n\n");
    printf(" 1 - Bubble Sort\n");
    printf(" 2 - Insertion Sort\n");
    printf(" 3 - Selection Sort\n");

    do
    {
        selecao = getch();
    } while (selecao < '1' || selecao > '3');

    switch (selecao)
    {
    case '1':
        BubbleSort(vetor, tam);
        break;
    case '2':
        InsertionSort(vetor, tam);
        break;
    case '3':
        SelectionSort(vetor, tam);
        break;
    }

    printf("\n\n Vetor ordenado: \n");
    ImprimeVetor(vetor, tam);

    printf("\n");
    return 0;
}

void BubbleSort(int v[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
        for (j = 0; j < n - i; j++)
            if (v[j] > v[j + 1])
                Troca(&v[j], &v[j + 1]);
}

void InsertionSort(int v[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        j = i;
        while (v[j] < v[j - 1] && j > 0)
        {
            Troca(&v[j], &v[j - 1]);
            j--;
        }
    }
}

void SelectionSort(int v[], int n)
{
    int i, j, menor;
    for (i = 0; i < n; i++)
    {
        menor = i;
        for (j = i + 1; j < n; j++)
            if (v[j] < v[menor])
                menor = j;
        Troca(&v[menor], &v[i]);
    }
}

void Troca(int *n1, int *n2)
{
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

void ImprimeVetor(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf(" %d ", v[i]);
}
