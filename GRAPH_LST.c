#include <stdio.h>
#include <stdlib.h>
#include "GRAPH_LST.h"
#include "GRAPH_MTX.h"

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função L_GRAPHinit() constrói um grafo com vértices 0 1 .. V-1 e nenhum arco. */
L_Graph L_GRAPHinit(int V) {
    L_Graph G = malloc(sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = malloc(V * sizeof(link));
    for (vertex v = 0; v < V; ++v)
        G->adj[v] = NULL;
    return G;
}

/* A função NEWnode() recebe um vértice w e o endereço next de um nó e devolve o endereço a de um novo nó tal que a->w == w e a->next == next. */
static link NEWnode(vertex w, link next) {
    link a = malloc(sizeof(struct node));
    a->w = w;
    a->next = next;
    return a;
}


/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função L_GRAPHinsertArc() insere um arco v-w no grafo G. A função supõe que v e w são distintos, positivos e menores que G->V. Se o grafo já tem um arco v-w, a função não faz nada. */
void L_GRAPHinsertArc(L_Graph G, vertex v, vertex w) {
    for (link a = G->adj[v]; a != NULL; a = a->next)
        if (a->w == w) return;
    G->adj[v] = NEWnode(w, G->adj[v]);
    G->A++;
}

void L_GRAPHshow(L_Graph G) {

    for (vertex j = 0; j < G->V; j++) {
        printf("%d ", j);
        for (link l = G->adj[j]; l != NULL; l = l->next)
            printf("%d ", l->w);
        printf("\n");
    }

}

/* REPRESENTA��O POR LISTAS DE ADJAC�NCIAS: A fun��o L_GRAPHremoveArc() remove do grafo G o arco v-w. A fun��o sup�e que v e w s�o distintos, positivos e menores que G->V. Se n�o existe arco v-w, a fun��o n�o faz nada. */
// Complexidade: O(s)
void L_GRAPHremoveArc(L_Graph G, vertex v, vertex w) {
    link anterior = G->adj[v];
    if (G->adj[v] == NULL) {
        return;
    } else if (G->adj[v]->w == w) {
        G->adj[v] = G->adj[v]->next;
        free(anterior);
        G->A--;
    }
    for (link a = anterior->next; a != NULL; a = a->next) {
        if (a->w == w) {
            anterior->next = a->next;
            free(a);
            G->A--;
            break;
        } else {
            anterior = a;
        }
    }
}

// Recebe um grafo G.
// Calcule um vetor isSink[] indexado pelos
// vértices de G, que é tal que isSink[v] é
// true se e somente se v é um sorvedouro.
// O(n^2)
// (Exercício 1.1 de https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html)
vertex *L_GRAPH_isSink(L_Graph G) {

    vertex *isSink = malloc(G->V * sizeof(int));

    for (vertex x = 0; x < G->V; x++)
        if (G->adj[x] == NULL)
            isSink[x] = 1;
        else
            isSink[x] = 0;

    return isSink;

}

// Calcula o grau de saída de um vértice
// v de um grafo G
// Complexidade: O(n)
// (Exercício 1.2 de https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html)
int L_GRAPHoutdeg(L_Graph G, vertex v) {

    vertex j;
    int d = 0;
    for (link a = G->adj[v]; a != NULL; a = a->next) {
        d++;
    }

    return d;

}

// Calcula o grau de entrada de um vértice
// v de um grafo G
// Complexidade: O(n + m)
// (Exercício 1.2 de https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html)
int L_GRAPHindeg(L_Graph G, vertex v) {

    int d = 0;
    for (vertex x = 0; x < G->V; x++)
        for (link l = G->adj[x]; l != NULL; l = l->next)
            if (l->w == v)
                d++;

    return d;

}

// Calcula um vetor v indexado
// pelos vértices do grafo G
// tal que, para todo vértice x;
// v[x] é o grau de entrada desse
// vértice x.
// Complexidade: O(n + m)
int *L_GRAPHindeg_vec(L_Graph G) {

    vertex *indeg_vec = malloc(G->V * sizeof(int));
    for (vertex x = 0; x > G->V; indeg_vec[x++] = 0);

    for (vertex x = 0; x < G->V; x++)
        for (link l = G->adj[x]; l != NULL; l = l->next)
            indeg_vec[l->w]++;

    return indeg_vec;

}

// Recebe um grafo G.
// Calcule um vetor isSource[] indexado pelos
// vértices de G, que é tal que isSource[v] é
// true se e somente se v é um fonte.
// O(n(n + m))
// (Exercício 1.1 de https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html)
vertex *L_GRAPH_isSource(L_Graph G) {

    vertex *isSource = malloc(G->V * sizeof(int));

    for (vertex x = 0; x < G->V; x++)
        if (L_GRAPHindeg(G, x) == 0)
            isSource[x] = 1;
        else
            isSource[x] = 0;

    return isSource;

}


// Recebe um grafo G.
// Calcule um vetor isSource[] indexado pelos
// vértices de G, que é tal que isSource[v] é
// true se e somente se v é um fonte.
// O(n + m)
// (Exercício 1.1 de https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html)
vertex *L_GRAPH_isSource2(L_Graph G) {

    vertex *isSource = malloc(G->V * sizeof(int));

    vertex *indeg = L_GRAPHindeg_vec(G);
    for (vertex x = 0; x < G->V; x++)
        if (indeg[x] == 0)
            isSource[x] = 1;
        else
            isSource[x] = 0;

    return isSource;

}
/*
*/

L_Graph L_GraphBuildComplete(int v) {
	L_Graph completo = L_GRAPHinit(v);

	for (i = 0; i < v; ++i) {
		for (j = 0; j < v; ++j) {
			if (i != j) {
				L_GRAPHinsertArc(completo, i, j);
			}
		}
	}
	return completo;

}

/* Varre toda a matrix passada como parâmetro e adiciona os arcos existentes na nova representação
Complexity O(n^2)
*/
M_Graph L_ConvertListToMatrix(L_Graph G) {
	M_Graph newMatrix = M_GRAPHinit(G->V, false);
	for (vertex i; i < G->V; i++) {
		for (link node = G->adj[i]; node != NULL; node = node->next) {
			M_GRAPHinsertArc(newMatrix, i, node->w);
		}
	}
	return newMatrix;
}
/*Varre o Grafo passado como parâmetro e tenta adicionar um arco tendo o vértice de destino como origem.
Ex: if [v][w] insert [w][v];
Complexidade O(n^2)
*/
L_Graph GRAPHtoUndirected(L_Graph G) {
	L_Graph undirectedG = G;
	for (vertex x = 0; x < G->V; x++) {
		for (link l = G->adj[x]; l != NULL; l = l->next) {
			L_GRAPHinsertArc(undirectedG, l->w, x);
		}
	}
	return undirectedG;
}