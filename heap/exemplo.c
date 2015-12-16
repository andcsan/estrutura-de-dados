#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main()
{
    HeapBin *heap_bin;
    int opcao, prio;
    char dado;

    heap_bin = HeapBin_criar();
    if (heap_bin == NULL)
    {
        printf("Nao foi possivel criar o heap binario!");
        return 0;
    }

    while (opcao != 5)
    {
        printf("\t\tHeap Binario: Fila de Prioridade\n");
        printf("Estrutura atual:\n");
        HeapBin_Imprimir(heap_bin);

        printf("\n\n1-Inserir\n\n2-Remover\n\n3-Apagar Heap\n\n4-Consulta qtd disponivel\n\n5-Sair");
        printf("\n\n\n\n\n\nOpcao: ");
        scanf("%d", &opcao);

        fflush(stdin);
        switch (opcao)
        {
        case 1:
            // inserir um novo elemento
            printf("\nElemento que deseja inserir[char]: ");
            scanf("%c", &dado);
            printf("Qual a prioridade do elemento[int]: ");
            scanf("%d", &prio);
            if (HeapBin_Inserir(heap_bin, dado, prio) == 0)
            {
                printf("->Nao foi possivel inserir o elemento solicitado. Verifique se a estrutura esta cheia!\n\n");
            }
            fflush(stdin);
            break;
        case 2:
            // remover o topo
            if (HeapBin_Remover(heap_bin))
            {
                printf("\nTopo removido com sucesso!\n");
            }
            else
            {
                printf("->Nao foi possivel remover, confira se a lista esta vazia!\n\n");
            }
            break;
        case 3:
            // libera alocacao de toda a fila
            HeapBin_libera(heap_bin);
            printf("->A memoria ocupada foi desalocada com exito.\n\n");
            break;
        case 4:
            // verifica a quantidade de elementos ainda disponiveis
            printf("->Voce ainda pode inserir %d elementos!\n", heap_bin->total_posicoes * -1 + 100);
            break;
        }
    }

    return 0;
}
