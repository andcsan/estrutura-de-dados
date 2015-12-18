#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int v[], int n);   // Função para ordenar o vetor por Bubble Sort
void Troca(int *n1, int *n2);      // Função para realizar a troca dos elementos quando necessário
void ImprimeVetor(int v[], int n); // Função para imprimir na tela o vetor

int main(void)
{
    int vetor[10] = {14, 62, 93, 84, 22, 37, 15, 20, 73, 55}; // Declarando um vetor inteiro com quaisquer valores
    int tam = 10;                                             // Declarando o tamanho do vetor

    // Imprime o vetor ainda não ordenado
    printf("\n Vetor nao ordenado: \n");
    ImprimeVetor(vetor, tam);

    // Realiza a ordenação por Bubble Sort
    BubbleSort(vetor, tam);

    // Imprime o vetor já ordenado
    printf("\n\n Vetor ordenado: \n");
    ImprimeVetor(vetor, tam);

    printf("\n\n");
    system("pause");

    return 0;
}

// Executa o algortimo do Bubble Sort
void BubbleSort(int v[], int n)
{
    int i, j;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                Troca(&v[j], &v[j + 1]);
            }
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
