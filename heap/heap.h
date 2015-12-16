// evita multiplas chamadas do header
#ifndef HEAP_H
#define HEAP_H

#define MAX 100

// estrutura com as informações que cada na tera
typedef struct nodo
{
    int prioridade;
    char dado;
} Nodo;

// Estrutura do heap, com um indice de total de posicoes, por se tratar de uma fila de prioridades estática
typedef struct heap_bin
{
    Nodo No[MAX];
    int total_posicoes;
} HeapBin;

// prototipos
// Funcao que retorna um heap
HeapBin *HeapBin_criar();

// Limpa espaço alocado pelo heap
void HeapBin_libera(HeapBin *);

// Retorna o tamanho total do heap
int HeapBin_tamanho(HeapBin *);

// Verifica se a estrutura ja esta cheia, por se tratar de uma fila de prioridades estática
int HeapBin_VerifCheia(HeapBin *);

// Verifica se a estrutura esta vazia
int FilaPriori_VerifVazia(HeapBin *);

// Insere na estrutura um novo elemento de acordo com a prioridade
int FilaPriori_Inserir(HeapBin *, char, int);

// Os novo elementos inseridos são sempre colocados na ultima posição, então essa função manipula a subida desse novo elemento caso ele tenha uma prioridade mais significativa
void manipula_array_sub(HeapBin *, int);

// A remoção sempre é do topo da fila de prioridade
int HeapBin_Remover(HeapBin *);

// Manipulação do array após a "remoção" de um elemento", onde para remover-lo o ultimo elemento é atribuido ao todo depois ocorre a manipulação do array verificando sua prioridade
void manipula_array_desc(HeapBin *, int);

// Impressão da fila de prioridades, com destaque para o elemento de maior prioridade
void HeapBin_Imprimir(HeapBin *);

#endif
