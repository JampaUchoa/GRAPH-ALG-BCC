#include <stdlib.h>
#include <stdio.h>
#include "GRAPH_MTX.h"
#include "GRAPH_LST.h"

/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o M_GRAPHinit() constr�i um grafo com v�rtices 0 1 .. V-1 e nenhum arco. */
M_Graph M_GRAPHinit(int V)
{
    M_Graph G = malloc(sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = MATRIXint(V, V, 0);
    return G;
}

/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o MATRIXint() aloca uma matriz com linhas 0..r-1 e colunas 0..c-1. Cada elemento da matriz recebe valor val. */
static int **MATRIXint(int r, int c, int val)
{
    int **m = malloc(r * sizeof(int *));
    vertex i;
    vertex j;
    for (i = 0; i < r; ++i)
        m[i] = malloc(c * sizeof(int));
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            m[i][j] = val;
    return m;
}
/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o M_GRAPHinsertArc() insere um arco v-w no grafo G. A fun��o sup�e que v e w s�o distintos, positivos e menores que G->V. Se o grafo j� tem um arco v-w, a fun��o n�o faz nada. */
// Complexidade: O(1)
void M_GRAPHinsertArc(M_Graph G, vertex v, vertex w)
{
    if (G->adj[v][w] == 0)
    {
        G->adj[v][w] = 1;
        G->A++;
    }
}
/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o M_GRAPHremoveArc() remove do grafo G o arco v-w. A fun��o sup�e que v e w s�o distintos, positivos e menores que G->V. Se n�o existe arco v-w, a fun��o n�o faz nada. */
// Complexidade: O(1)
void M_GRAPHremoveArc(M_Graph G, vertex v, vertex w)
{
    if (G->adj[v][w] == 1)
    {
        G->adj[v][w] = 0;
        G->A--;
    }
}

/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o M_GRAPHshow() imprime, para cada v�rtice v do grafo G, em uma linha, todos os v�rtices adjacentes a v. */
void M_GRAPHshow(M_Graph G)
{
    vertex v;
    vertex w;

    for (v = 0; v < G->V; ++v)
    {
        printf("%2d:", v);
        for (w = 0; w < G->V; ++w)
            if (G->adj[v][w] == 1)
                printf(" %2d", w);
        printf("\n");
    }
}

// Recebe um grafo G.
// Calcule um vetor isSink[] indexado pelos
// vértices de G, que é tal que isSink[v] é
// true se e somente se v é um sorvedouro.
// O(n^2)
// (Exercício 1.1 de https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html)
vertex *M_GRAPH_isSink(M_Graph G)
{

    vertex *isSink = malloc(G->V * sizeof(int));
    vertex x;
    for (x = 0; x < G->V; x++)
        if (M_GRAPHoutdeg(G, x) == 0)
            isSink[x] = 1;
        else
            isSink[x] = 0;

    return isSink;

}

// Recebe um grafo G.
// Calcule um vetor isSource[] indexado pelos
// vértices de G, que é tal que isSource[v] é
// true se e somente se v é um fonte.
// O(n^2)
// (Exercício 1.1 de https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html)
vertex *M_GRAPH_isSource(M_Graph G)
{

    vertex *isSource = malloc(G->V * sizeof(int));
    vertex x;
    for (x = 0; x < G->V; x++)
        if (M_GRAPHindeg(G, x) == 0)
            isSource[x] = 1;
        else
            isSource[x] = 0;

    return isSource;

}

// Calcula o grau de saída de um vértice
// v de um grafo G
// Complexidade: O(n)
// (Exercício 1.2 de https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html)
int M_GRAPHoutdeg(M_Graph G, vertex v)
{

    vertex j;
    int d = 0;
    for (j = 0; j < G->V; j++)
        if (G->adj[v][j] == 1)
            d++;

    return d;

}

// Calcula o grau de entrada de um vértice
// v de um grafo G
// Complexidade: O(n)
// (Exercício 1.2 de https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html)
int M_GRAPHindeg(M_Graph G, vertex v)
{

    vertex j;
    int d = 0;
    for (j = 0; j < G->V; j++)
        if (G->adj[j][v] == 1)
            d++;

    return d;

}

// Testa se um vértice v de um grafo G é
// isolado.
// Complexidade: O(n)
// (Exercício 1.3 de https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html)
int M_GRAPHisolated(M_Graph G, vertex v)
{

    return (M_GRAPHindeg(G, v) == 0) && (M_GRAPHoutdeg(G, v) == 0);
}


// Recebe um grafo G e devolve um
// outro grafo que é o reverso de G.
// (Exercício 1.10 de https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html)
// Complexidade: O(n^2)
M_Graph M_GRAPHreverse(M_Graph G)
{

    M_Graph H = M_GRAPHinit(G->V);
    H->A = G->A;
    int j;
    int k;
    for (j = 0; j < G->V; j++)
        for (k = 0; k < G->V; k++)
            H->adj[j][k] = G->adj[k][j];


    return H;

}

// Testa se um grafo G é um torneio
// usando o Teorema Tavares-Uchoa:
// G com n vértices é torneio sse
// para todo vértice v, g+(v) + g-(v) = n - 1.
// Complexidade: O(n^2)
// (Exercício 1.12 de https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html)
int M_isTournament(M_Graph G)
{

    vertex v;

    for (v = 0; v < G->V; v++)
        if (M_GRAPHindeg(G, v) + M_GRAPHoutdeg(G, v) != G->V - 1)
            return 0;

    return 1;

}

// Testa se w é adjacente a v num graph G
// Complexidade: O(1)
// (Exercício 1.4 de https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html)
int M_GRAPHisadj(M_Graph G, vertex v, vertex w)
{
    return G->adj[v][w];
}

// Recebe um grafo G e devolve um novo grafo,
// representando o complemento de G
// Complexidade: O(n^2)
M_Graph M_GRAPHcomplement(M_Graph G)
{

    M_Graph H = M_GRAPHinit(G->V);
    int i;
    int j;
    for (i = 0; i < G->V; i++)
        for (j = 0; j < G->V; j++)
            if ((i != j) && !M_GRAPHisadj(G, i, j))
                M_GRAPHinsertArc(H, i, j);

    return H;

}

// Cria um grafo completo iniciando todos os valores
// da matriz como 1 exceto os da diagonal principal
// Complexidade O(n^2)
M_Graph M_GRAPHbuildComplete(int V)
{

    int **m = malloc(V * sizeof(int *));
    vertex i;
    vertex j;
    for (i = 0; i < V; ++i)
        m[i] = malloc(V * sizeof(int));
    for (i = 0; i < V; ++i)
        for (j = 0; j < V; ++j)
            if (i != j)
                m[i][j] = 1;

    M_Graph G = malloc(sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = m;
    return G;
}

// Converte a representação do grafo de matriz para lista de ajacencias
// Complexidade: O(n^2)
L_Graph M_GRAPHconvert(M_Graph G)
{

    L_Graph lGraph = L_GRAPHinit(G->V);
    int i;
    int j;
    for (i = 0; i < G->V; i++)
        for (j = 0; j < G->V; j++)
            if (M_GRAPHisadj(G, i, j))
                L_GRAPHinsertArc(lGraph, i, j);
    return lGraph;
}

// Recebe um grafo G e acrescenta um arco antiparalelo a cada arco de G.
// Complexidade: O(n^2)
void GRAPHtoUndirected(M_Graph G)
{
    int i;
    int j;
    for (i = 0; i < G->V; i++)
        for (j = 0; j < G->V; j++)
            if (M_GRAPHisadj(G, i, j))
                M_GRAPHinsertArc(G, j, i);
}


//Aluno :Givanildo Júnior
//Recebe um numero de vertice V e retorna uma grafo ciclico
//complexidade: 0(n)
//Exercicio: 1.3   Link : www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/builders.html
M_Graph UGRAPHbuildCycle(int V)
{
    M_Graph gCycle = M_GRAPHinit(V);
    int i;
    for(i = 0; i <= gCycle->V; i++)
    {
        if (gCycle->adj[i][i+1] == 0)
        {
            gCycle->adj[i][i+1] = 1;
            gCycle->A++;
        }
        else
        {
            if(gCycle->adj[i][0] == 0)
            {
                gCycle->adj[i][0]=1;
                gCycle->A++;
            }
        }
    }
    return gCycle;
}

//Aluno :Givanildo Júnior
//verificar se um dado grafo é um torneio
//Teorema tavares e uchoa utilizado em sala de aula
//complexidade: 0(n^2)
//Exercicio: 1.12   https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html

int isTournament(M_Graph G)
{

    vertex v;

    for (v = 0; v < G->V; v++)
        if (M_GRAPHindeg(G, v) + M_GRAPHoutdeg(G, v) != G->V - 1)
            return 0;

    return 1;

}

//Aluno :Givanildo Júnior
//Recebe um numero de vertice V e retorna uma grafo completo
//complexidade: 0(n^2)
//Exercicio: 2.2   Link : www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/builders.html

M_Graph UGRAPHcomplete(int V)
{
    int **m = malloc(V * sizeof(int *));
    vertex i;
    vertex j;
    for (i = 0; i < V; ++i)
        m[i] = malloc(V * sizeof(int));
    for (i = 0; i < V; ++i)
        for (j = 0; j < V; ++j)
            if (i != j)
                m[i][j] = 1;

    M_Graph G = malloc(sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = m;
    return G;

}
