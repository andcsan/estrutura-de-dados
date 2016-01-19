#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

HeapBin *HeapBin_criar(void)
{
    HeapBin *aux;
    aux = (HeapBin *)malloc(sizeof(HeapBin)); // necessária alocação para não perder o local ao final da função

    // verifica se foi alocada corretamente
    if (aux != NULL)
    {
        aux->total_posicoes = 0;
        return aux;
    }
    else
    {
        return NULL;
    }
}

void HeapBin_libera(HeapBin *hp)
{
    hp->total_posicoes = 0;
    free(hp); // libera espaço que foi alocado pelo heap
}

int HeapBin_tamanho(HeapBin *hp)
{
    if (hp == NULL)
    {
        return -1;
    }
    else
    {
        // retorno do campo da estrutura que armazena o total de posições
        return hp->total_posicoes;
    }
}

int HeapBin_VerifCheia(HeapBin *hp)
{
    if (hp == NULL)
    {
        return -1;
    }
    else
    {
        return (hp->total_posicoes == MAX);
    }
}

int HeapBin_VerifVazia(HeapBin *hp)
{
    if (hp == NULL)
    {
        return -1;
    }
    else
    {
        return (hp->total_posicoes == 0);
    }
}

int HeapBin_Inserir(HeapBin *hp, char c, int priori)
{
    if (hp == NULL || HeapBin_VerifCheia(hp))
    {
        return 0;
    }

    hp->No[hp->total_posicoes].dado = c;            // atribuindo o caractere de inserção na última posição do array
    hp->No[hp->total_posicoes].prioridade = priori; // atribuindo a prioridade do caractere
    manipula_array_sub(hp, hp->total_posicoes);     // comparando prioridade de pai e filho e trocando caso a prioridade do pai seja menor
    hp->total_posicoes++;                           // incrementando a quantidade total de posições
    return 1;
}

void manipula_array_sub(HeapBin *hp, int posicao_filho)
{
    int posicao_pai = (posicao_filho - 1) / 2; // definindo o pai atual
    Nodo auxiliar;                             // auxiliar para realizar a troca, em caso de prioridade menor do pai

    // enquanto a posição filho não for o topo e o posição pai for menor em comparação a prioridade
    while ((posicao_filho > 0) && (hp->No[posicao_pai].prioridade) <= (hp->No[posicao_filho].prioridade))
    {
        // realizando a troca através do auxiliar
        auxiliar = hp->No[posicao_filho];
        hp->No[posicao_filho] = hp->No[posicao_pai];
        hp->No[posicao_pai] = auxiliar;

        posicao_filho = posicao_pai;         // posição filho passou a ser a posição pai depois da troca
        posicao_pai = (posicao_pai - 1) / 2; // encontrando o novo pai
    }
}

int HeapBin_Remover(HeapBin *hp)
{
    if (hp == NULL || HeapBin_VerifVazia(hp))
    {
        return 0;
    }

    hp->total_posicoes--;
    hp->No[0] = hp->No[hp->total_posicoes]; // atribuindo a ultima posição ao topo, já que a remoção sempre acontece do de maior prioridade
    manipula_array_desc(hp, 0);             // comparando prioridade do atual topo(pai) com a de seus filhos e trocando
    return 1;
}

void manipula_array_desc(HeapBin *hp, int posicao_pai)
{
    Nodo auxiliar;                           // auxiliar para realizar a troca, em caso de prioridade menor do pai
    int posicao_filho = 2 * posicao_pai + 1; // encontrando a posição do filho da direita

    while (posicao_filho < hp->total_posicoes)
    {
        if (posicao_filho < hp->total_posicoes - 1)
        {
            // verificação se existe um irmão
            if (hp->No[posicao_filho].prioridade < hp->No[posicao_filho + 1].prioridade)
            {

                posicao_filho++;
            }
        }

        // se a posição do pai for maior que o filho de maior prioridade, encerra-se o while
        if (hp->No[posicao_pai].prioridade >= hp->No[posicao_filho].prioridade)
        {
            break;
        }

        auxiliar = hp->No[posicao_pai];
        hp->No[posicao_pai] = hp->No[posicao_filho];
        hp->No[posicao_filho] = auxiliar;

        posicao_pai = posicao_filho;
        posicao_filho = 2 * posicao_pai + 1; // novo filho
    }
}

void HeapBin_Imprimir(HeapBin *hp)
{
    int tam = hp->total_posicoes;
    int i;

    printf("Dado[Prioridade]\n\n");

    if (tam != 0)
    {
        printf("%c[%d]<-TOPO\n\n", hp->No[0].dado, hp->No[0].prioridade);
    }

    for (i = 0; i < tam; i++)
    {
        printf("%c[%d] ", hp->No[i].dado, hp->No[i].prioridade);
    }

    printf("\n");
}
