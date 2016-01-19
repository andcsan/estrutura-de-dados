#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int v[], int n); // Função para ordenar o vetor por Insertion Sort
void Troca(int *n1, int *n2);       // Função para realizar a troca dos elementos quando necessário
void ImprimeVetor(int v[], int n);  // Função para imprimir na tela o vetor

int main(void)
{
    int vetor[10] = {50, 41, 97, 10, 34, 12, 68, 76, 84, 22}; // Declarando um vetor inteiro com quaisquer valores
    int tam = 10;                                             // Declarando o tamanho do vetor

    // Imprime o vetor ainda não ordenado
    printf("\n Vetor nao ordenado: \n");
    ImprimeVetor(vetor, tam);

    // Realiza a ordenação por Insertion Sort
    InsertionSort(vetor, tam);

    // Imprime o vetor já ordenado
    printf("\n\n Vetor ordenado: \n");
    ImprimeVetor(vetor, tam);

    printf("\n\n");
    system("pause");

    return 0;
}

// Executa o algoritmo do Insertion Sort
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

// Recebe como parametro o endereço dos elementos que serão trocados
void Troca(int *n1, int *n2)
{
    int aux = *n1;

    *n1 = *n2;
    *n2 = aux;
}

// Recebe como parametro o vetor e seu tamanho para imprimir na tela
void ImprimeVetor(int v[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf(" %d ", v[i]);
    }
}
