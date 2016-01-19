// evita multiplas chamadas do header
#ifndef PILHA_H
#define PILHA_H

typedef struct no No; // define um nome para estrutura nó
typedef No *Pilha;    // define um nome para um ponteiro de estrutura nó

// prototipos
// inicia uma pilha com valor nulo
void pilha_iniciar(Pilha *);

// insere um novo nó na pilha com o elemento escolhido
void pilha_inserir(Pilha *, int);

// remove o elemento no topo da pilha
void pilha_remover(Pilha *);

// imprime a pilha
void pilha_listar(Pilha *);

// pesquisa a posição de um elemento no pilha, a partir da base da pilha
void pilha_pesquisar(Pilha *, int);

// deleta a pilha por inteiro
void pilha_deletar(Pilha *);

// verifica se a pilha está vazia e retorna verdadeiro caso esteja
int pilha_vazia(Pilha *);

#endif
