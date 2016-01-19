#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    Pilha pilha; // cria uma pilha
    int opcao, elemento;

    pilha_iniciar(&pilha); // inicia uma pilha vazia
    while (opcao != 5)
    {
        printf("\n1-Inserir\n2-Remover\n3-Pesquisar\n4-Apagar pilha\n5-Sair");
        pilha_listar(&pilha); // imprime a pilha para o usuário
        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nElemento que deseja inserir: ");
            scanf("%d", &elemento);
            pilha_inserir(&pilha, elemento); // insere o elemento escolhido na pilha
            break;
        case 2:
            // verifica se a pilha não está vazia
            if (!pilha_vazia(&pilha))
            {
                pilha_remover(&pilha); // remove o elemento no topo da pilha
            }
            else
            {
                printf("\nPilha ja esta vazia!\n");
            }
            break;
        case 3:
            printf("\nElemento que deseja pesquisar: ");
            scanf("%d", &elemento);
            pilha_pesquisar(&pilha, elemento); // procura um elemento na pilha
            break;
        case 4:
            pilha_deletar(&pilha); // deleta a pilha
            printf("\nPilha deletada.\n");
            break;
        }
    }

    pilha_deletar(&pilha); // deleta a pilha ao encerrar a aplicação

    return 0;
}
