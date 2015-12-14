#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Lista lista; // cria uma lista
    int opcao, elemento;

    lista_iniciar(&lista); // inicia uma lista vazia

    while (opcao != 5)
    {
        printf("\n1-Inserir\n2-Remover\n3-Pesquisar\n4-Apagar lista\n5-Sair");
        lista_listar(&lista); // imprime a lista para o usuário

        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nElemento que deseja inserir: ");
            scanf("%d", &elemento);
            lista_inserir(&lista, elemento); // insere um novo elemento na lista
            break;
        case 2:
            // verifica se a lista não está vazia
            if (!lista_vazia(&lista))
            {
                printf("\nElemento que deseja remover: ");
                scanf("%d", &elemento);
                lista_remover(&lista, elemento); // remove um elemento escolhido pelo usuário
            }
            else
            {
                printf("\nLista ja esta vazia!\n");
            }
            break;
        case 3:
            printf("\nElemento que deseja pesquisar: ");
            scanf("%d", &elemento);
            lista_pesquisar(&lista, elemento); // procura um elemento na lista
            break;
        case 4:
            lista_deletar(&lista); // deleta a lista
            printf("\nLista deletada.\n");
            break;
        }
    }

    lista_deletar(&lista); // deleta a lista antes de encerrar a aplicação

    return 0;
}
