#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// estrutura para representar cada nó da pilha
struct no
{
    int elemento; // elemento a ser armazenado
    No *proximo;  // ponteiro para o próximo nó
    No *anterior; // ponteiro para o nó anterior
};

// inicia uma pilha com valor nulo
void pilha_iniciar(Pilha *pi)
{
    *pi = NULL; // inicia a cabeca da pilha apontando para um nulo
}

// insere um novo nó na pilha com o elemento escolhido
void pilha_inserir(Pilha *pi, int valor)
{
    No *no_novo;   // ponteiro para o novo nó que será criado
    No *no_aux;    // ponteiro de nó para caminhar a pilha
    No *no_previo; // ponteiro de nó para armazenar o ultimo valor do nó auxiliar

    no_novo = (No *)malloc(sizeof(struct no)); // aloca memória para o novo nó criado

    if (no_novo != NULL) // caso tenha sido possível alocar memória
    {
        no_novo->elemento = valor; // coloca o elemento no novo nó
        no_novo->proximo = NULL;
        no_novo->anterior = NULL;

        no_aux = *pi; // começa a caminhar a partir do começo da pilha
        no_previo = NULL;

        // se a pilha está vazia
        if (no_aux != NULL)
        {
            // enquanto não chegar no topo da pilha, continua caminhando
            while (no_aux != NULL)
            {
                no_previo = no_aux;
                no_aux = no_aux->proximo;
            }

            // insere o novo nó na ultima posição
            no_previo->proximo = no_novo;
            no_novo->anterior = no_previo;
        }
        // se estiver vazia, o ponteiro de cabeça passa a apontar para o novo nó
        else
        {
            *pi = no_novo;
        }
    }
    else
    {
        printf("Sem memoria suficiente para alocar.\n");
    }
}

// remove o elemento no topo da pilha
void pilha_remover(Pilha *pi)
{
    No *no_aux; // nó para caminhar na pilha
    No *no_previo;
    int valor; // valor do elemento do nó que será removido

    no_aux = *pi; // começa a caminhar a partir do começo da pilha
    no_previo = NULL;

    // enquanto não chegar no topo da pilha
    while (no_aux != NULL)
    {
        no_previo = no_aux;
        no_aux = no_aux->proximo;
    }

    // recebe o elemento do nó ue será removido
    valor = no_previo->elemento;

    // se o nó que será removido é o último da pilha
    if (no_previo->anterior == NULL)
    {
        // cabeça passa a apontar para nulo
        *pi = NULL;
        // senão, o elemento do novo topo passa a apontar para nulo
    }
    else
    {
        (no_previo->anterior)->proximo = NULL;
    }

    // libera a memória alocado do topo antigo
    free(no_previo);

    printf("\nElemento %d removido.\n", valor);
}

// imprime a pilha
void pilha_listar(Pilha *pi)
{
    No *no_aux;

    no_aux = *pi; // começa a caminhar a partir do começo da pilha

    printf("\n\n");
    // se a pilha estiver vazia
    if (*pi == NULL)
    {
        printf("Pilha vazia.\n");
        return; // retorna
    }

    // enquanto não chegar ao topo da pilha
    while (no_aux != NULL)
    {
        printf("%d -> ", no_aux->elemento);
        no_aux = no_aux->proximo;
    }
    printf("Null\n");
}

// pesquisa a posição de um elemento no pilha, a partir da base da pilha
void pilha_pesquisar(Pilha *pi, int valor)
{
    int contador; // contador para a quantidade de elementos caminhados
    No *no_aux;
    no_aux = *pi; // começa a caminhar a partir do começo da pilha

    contador = 1;

    // enquanto não chegar ao topo da pilha ou não encontrar o elemento procurado
    while (no_aux != NULL && no_aux->elemento != valor)
    {
        no_aux = no_aux->proximo;
        ++contador;
    }

    // caso caminhe a pilha inteira sem encontrar o elemento procurado
    if (no_aux == NULL)
    {
        printf("\nElemento nao encontrado.\n");
    }
    else
    {
        printf("\nElemento encontrado na posicao %d da pilha\n", contador);
    }
}

// deleta a pilha por inteiro
void pilha_deletar(Pilha *pi)
{
    No *no_aux;
    No *no_del;

    no_aux = *pi; // começa a caminhar a partir do começo da pilha

    // caminha a pilha até o topo
    while (no_aux != NULL)
    {
        no_del = no_aux;
        no_aux = no_aux->proximo;

        // remove o elemento cujo nó caminhante acabou de passar
        free(no_del);
    }
    *pi = NULL;
}

// verifica se a pilha está vazia e retorna verdadeiro caso esteja
int pilha_vazia(Pilha *pi)
{
    return *pi == NULL;
}
