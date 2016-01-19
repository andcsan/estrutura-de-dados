// evita multiplas chamadas do header
#ifndef LISTA_H
#define LISTA_H

typedef struct no No; // define um nome para estrutura nó
typedef No *Lista;    // define um nome para um ponteiro de estrutura nó

// prototipos
// inicia a lista com valor nulo
void lista_iniciar(Lista *);

// insere um novo elemento na lista
void lista_inserir(Lista *, int);

// remove um elemento escolhido da lista
void lista_remover(Lista *, int);

// imprime a lista
void lista_listar(Lista *);

// pesquisa a posição de um elemento na lista
void lista_pesquisar(Lista *, int);

// deleta a lista inteira
void lista_deletar(Lista *);

// verifica se a lista está vazia e retorna verdadeiro caso esteja
int lista_vazia(Lista *);

#endif
