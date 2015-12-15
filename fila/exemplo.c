#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    Fila fila; // cria uma fila
    int opcao, elemento;

    fila_iniciar(&fila); // inicia um fila vazia

    while (opcao != 5)
    {
        printf("\n1-Inserir\n2-Remover\n3-Pesquisar\n4-Apagar fila\n5-Sair");
        fila_listar(&fila);

        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nElemento que deseja inserir: ");
            scanf("%d", &elemento);
            fila_inserir(&fila, elemento);
            break;
        case 2:
            if (!fila_vazia(&fila))
            {
                fila_remover(&fila);
            }
            else
            {
                printf("\nFila ja esta vazia!\n");
            }
            break;
        case 3:
            printf("\nElemento que deseja pesquisar: ");
            scanf("%d", &elemento);
            fila_pesquisar(&fila, elemento);
            break;
        case 4:
            fila_deletar(&fila);
            printf("\nFila deletada.\n");
            break;
        }
    }

    fila_deletar(&fila); // deleta a fila antes de encerrar a aplicação

    return 0;
}
