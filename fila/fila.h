// evita multiplas chamadas do header
#ifndef FILA_H
#define FILA_H

typedef struct no No; // define um nome para estrutura nó
typedef No *Fila;     // define um nome para um ponteiro de estrutura nó

// prototipos
// inicia uma fila com valor nulo
void fila_iniciar(Fila *);

// insere um novo nó na fila com o elemento escolhido
void fila_inserir(Fila *, int);

// remove o elemento no início da fila
void fila_remover(Fila *);

// imprime a fila
void fila_listar(Fila *);

// pesquisa a posição de um elemento na fila
void fila_pesquisar(Fila *, int);

// deleta a fila inteira
void fila_deletar(Fila *);

// verifica se a fila está vazia e retorna verdadeiro caso esteja
int fila_vazia(Fila *);

#endif
