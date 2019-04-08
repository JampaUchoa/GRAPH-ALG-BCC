#ifndef GRAPH_LST_H
#define GRAPH_LST_H

/* Vértices de grafos são representados por objetos do tipo vertex. */
#define vertex int

typedef struct node *link;

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A estrutura graph representa um grafo. O campo adj é um ponteiro para o vetor de listas de adjacência, o campo V contém o número de vértices e o campo A contém o número de arcos do grafo. */
struct l_graph {
    int V;
    int A;
    link *adj;
};
/* Um L_Graph é um ponteiro para um graph. */
typedef struct l_graph *L_Graph;
/* A lista de adjacência de um vértice v é composta por nós do tipo node. Cada nó da lista corresponde a um arco e contém um vizinho w de v e o endereço do nó seguinte da lista. Um link é um ponteiro para um node. */

struct node {
    vertex w;
    link next;
};

/* A função NEWnode() recebe um vértice w e o endereço next de um nó e devolve o endereço a de um novo nó tal que a->w == w e a->next == next. */
static link NEWnode(vertex w, link next);

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função L_GRAPHinit() constrói um grafo com vértices 0 1 .. V-1 e nenhum arco. */
L_Graph L_GRAPHinit(int V);

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função L_GRAPHinsertArc() insere um arco v-w no grafo G. A função supõe que v e w são distintos, positivos e menores que G->V. Se o grafo já tem um arco v-w, a função não faz nada. */
void L_GRAPHinsertArc(L_Graph G, vertex v, vertex w);

void L_GRAPHshow(L_Graph G);

/* REPRESENTA��O POR LISTAS DE ADJAC�NCIAS: A fun��o L_GRAPHremoveArc() remove do grafo G o arco v-w. A fun��o sup�e que v e w s�o distintos, positivos e menores que G->V. Se n�o existe arco v-w, a fun��o n�o faz nada. */
// Complexidade: O(1)
void L_GRAPHremoveArc(L_Graph G, vertex v, vertex w);


vertex *L_GRAPH_isSink(L_Graph G);

// Calcula o grau de entrada de um vértice
// v de um grafo G
// Complexidade: O(n)
// (Exercício 1.2 de https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html)
int L_GRAPHindeg(L_Graph G, vertex v);

// Recebe um grafo G.
// Calcule um vetor isSource[] indexado pelos
// vértices de G, que é tal que isSource[v] é
// true se e somente se v é um fonte.
// O(n^2)
// (Exercício 1.1 de https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html)
vertex *L_GRAPH_isSource(L_Graph G);

vertex *L_GRAPH_isSource2(L_Graph G);

#endif