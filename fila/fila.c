#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// estrutura para representar cada nó da fila
struct no
{
    int elemento; // elemento a ser armazenado
    No *proximo;  // ponteiro para o próximo nó
};

// inicia uma fila com valor nulo
void fila_iniciar(Fila *fi)
{
    *fi = NULL; // inicia a cabeca da fila apontando para um nulo
}

// insere um novo nó na fila com o elemento escolhido
void fila_inserir(Fila *fi, int valor)
{
    No *no_novo;   // ponteiro para o novo nó que será criado
    No *no_aux;    // ponteiro de nó para caminhar a fila
    No *no_previo; // ponteiro de nó para armazenar o ultimo valor do nó auxiliar

    no_novo = (No *)malloc(sizeof(struct no)); // aloca memória para o novo nó criado

    // caso tenha sido possível alocar memória
    if (no_novo != NULL)
    {
        no_novo->elemento = valor;
        no_novo->proximo = NULL;

        no_aux = *fi; // começa a caminhar a partir do começo da fila
        no_previo = NULL;

        // se a fila está vazia
        if (no_aux != NULL)
        {
            // enquanto não chegar no fim da fila, continua caminhando
            while (no_aux != NULL)
            {
                no_previo = no_aux;
                no_aux = no_aux->proximo;
            }

            no_previo->proximo = no_novo; // insere o novo nó na ultima posição
        }
        // se estiver vazia, o ponteiro de cabeça passa a apontar para o novo nó
        else
        {
            *fi = no_novo;
        }
    }
    else
    {
        printf("Sem memoria suficiente para alocar.\n");
    }
}

// remove o elemento no início da fila
void fila_remover(Fila *fi)
{
    No *no_aux;
    int valor;

    no_aux = *fi;             // nó auxiliar aponta para a cabeça da fila
    *fi = no_aux->proximo;    // cabeça passa a apontar para o segundo nó da fila
    valor = no_aux->elemento; // guarda o elemento do nó que será removido
    free(no_aux);             // libera a memória do antigo nó

    printf("\nElemento %d removido.\n", valor);
}

// imprime a fila
void fila_listar(Fila *fi)
{
    No *no_aux;

    no_aux = *fi; // começa a caminhar a partir do início da fila

    printf("\n\n");

    // se a fila está vazia, retorna
    if (*fi == NULL)
    {
        printf("Fila vazia.\n");
        return;
    }

    // caminha a fila até o fim, imprimindo os elementos
    while (no_aux != NULL)
    {
        printf("%d -> ", no_aux->elemento);
        no_aux = no_aux->proximo;
    }

    printf("Null\n");
}

// pesquisa a posição de um elemento na fila
void fila_pesquisar(Fila *fi, int valor)
{
    int contador; // contador para a quantidade de elementos caminhados
    No *no_aux;
    no_aux = *fi; // começa a caminhar a partir do início da fila

    contador = 1;

    // caminha a fila até encontrar o elemento procurado
    while (no_aux != NULL && no_aux->elemento != valor)
    {
        no_aux = no_aux->proximo;
        ++contador;
    }

    // se caminhou a fila inteira sem encontrar o elemento
    if (no_aux == NULL)
    {
        printf("\nElemento nao encontrado.\n");
    }
    else
    {
        printf("\nElemento encontrado na posicao %d da fila.\n", contador);
    }
}

// deleta a fila inteira
void fila_deletar(Fila *fi)
{
    No *no_aux;
    No *no_del;

    no_aux = *fi; // começa a caminhar a partir do início da fila

    // caminha até o fim da fila, removendo os nós
    while (no_aux != NULL)
    {
        no_del = no_aux;
        no_aux = no_aux->proximo;
        free(no_del);
    }

    *fi = NULL; // cabeça da fila volta a ser nula
}

// verifica se a fila está vazia e retorna verdadeiro caso esteja
int fila_vazia(Fila *fi)
{
    return *fi == NULL;
}
