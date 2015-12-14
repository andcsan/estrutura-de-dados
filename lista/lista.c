#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// estrutura para representar cada nó da lista
struct no
{
    int elemento; // elemento a ser armazenado no nó
    No *proximo;  // ponteiro para o próximo nó
    No *anterior; // ponteiro para o nó anterior
};

// inicia a lista com valor nulo
void lista_iniciar(Lista *li)
{
    *li = NULL; // inicia a cabeca da lista apontando para um nulo
}

// insere um novo elemento na lista
void lista_inserir(Lista *li, int valor)
{
    No *no_novo;   // ponteiro para o nó a ser alocado
    No *no_aux;    // ponteiro para caminhar a lista
    No *no_previo; // ponteiro para o nó anterior ao nó auxiliar

    no_novo = (No *)malloc(sizeof(struct no)); // aloca espaço de memória para o novo nó

    if (no_novo != NULL) // caso tenha sido possível alocar memória
    {
        no_novo->elemento = valor; // insere o elemento no novo nó
        no_novo->proximo = NULL;
        no_novo->anterior = NULL;

        no_aux = *li; // começa a caminha a partir do inicio
        no_previo = NULL;

        // caso a lista não esteja vazia
        if (no_aux != NULL)
        {
            // caminha até encontrar sua posição na lista
            while (no_aux != NULL && valor > no_aux->elemento)
            {
                no_previo = no_aux;
                no_aux = no_aux->proximo;
            }

            // se não for inserir no começo da lista
            if (no_previo != NULL)
            {
                no_novo->anterior = no_previo;
                no_previo->proximo = no_novo;
            }
            else // insere no começo da lista
            {
                no_aux = *li;
                no_novo->proximo = no_aux;
                no_aux->anterior = no_novo;
                *li = no_novo;
            }

            // se não for inserir no fim da lista
            if (no_aux != NULL)
            {
                no_novo->proximo = no_aux;
                no_aux->anterior = no_novo;
            }
        }
        else // cabeça apontar para o novo nó caso a lista esteja vazia
        {
            *li = no_novo;
        }
    }
    else
    {
        printf("Sem memoria suficiente para alocar.\n");
    }
}

// remove um elemento escolhido da lista
void lista_remover(Lista *li, int valor)
{
    No *no_aux;    // ponteiro para caminhar na lista
    No *no_previo; // ponteiro para o nó anterior

    no_aux = *li; // caminha desde o começo da lista
    no_previo = NULL;

    // enquanto não encontrar o elemento a ser removido
    while (no_aux != NULL && no_aux->elemento != valor)
    {
        no_previo = no_aux;
        no_aux = no_aux->proximo;
    }
    // caso percorra a lista inteira sem encontrar o elemento procurado
    if (no_aux == NULL)
    {
        printf("\nElemento nao encontrado.\n");
    }
    else // caso encontre o elemento procurado
    {
        // se o elemento procurado não estiver no começo da lista
        if (no_previo != NULL)
            no_previo->proximo = no_aux->proximo;
        else
            *li = no_aux->proximo;

        // se o elemento a ser removido não está no último nó da lista
        if (no_aux->proximo != NULL)
            (no_aux->proximo)->anterior = no_aux->anterior;
        else
            // se o elemento a ser removido é o único da lista
            if (no_previo != NULL)
                no_previo->proximo = NULL;

        free(no_aux); // libera o espaço alocado
        printf("\nElemento %d removido.\n", valor);
    }
}

// imprime a lista
void lista_listar(Lista *li)
{
    No *no_aux;

    no_aux = *li; // caminha desde o começo da lista

    printf("\n\n");
    // se a lista está vazia
    if (*li == NULL)
    {
        printf("Lista vazia.\n");
        return; // retorna
    }
    // caminha a lista até o fim
    while (no_aux != NULL)
    {
        printf("%d -> ", no_aux->elemento);
        no_aux = no_aux->proximo;
    }
    printf("Null\n");
}

// pesquisa a posição de um elemento na lista
void lista_pesquisar(Lista *li, int valor)
{
    int contador; // contador para a quantidade de elementos caminhados
    No *no_aux;
    no_aux = *li; // caminha desde o começo da lista

    contador = 1;

    // caminha a lista até encontrar o elemento procurado
    while (no_aux != NULL && no_aux->elemento != valor)
    {
        no_aux = no_aux->proximo;
        ++contador; // conta a quantidade de saltos
    }

    // se percorreu a lista inteira sem encontrar o elemento procurado
    if (no_aux == NULL)
    {
        printf("\nElemento nao encontrado.\n");
    }
    else
    {
        printf("\nElemento encontrado na posicao %d da lista.\n", contador);
    }
}

// deleta a lista inteira
void lista_deletar(Lista *li)
{
    No *no_aux;
    No *no_del;

    no_aux = *li; // caminha desde o começo da lista

    // caminha a lista até o fim, removendo todos os nós
    while (no_aux != NULL)
    {
        no_del = no_aux;
        no_aux = no_aux->proximo;
        free(no_del); // libera a memória alocada pelo nó
    }

    *li = NULL; // cabeça da lista passa a apontar para nulo
}

// verifica se a lista está vazia e retorna verdadeiro caso esteja
int lista_vazia(Lista *li)
{
    return *li == NULL;
}
