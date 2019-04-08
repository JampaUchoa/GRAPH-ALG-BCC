/* V�rtices de grafos s�o representados por objetos do tipo vertex. */
#define vertex int

/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A estrutura graph representa um grafo. O campo adj � um ponteiro para a matriz de adjac�ncias do grafo. O campo V cont�m o n�mero de v�rtices e o campo A cont�m o n�mero de arcos do grafo. */
struct m_graph {
    int V;
    int A;
    int **adj;
};
/* Um Graph � um ponteiro para um graph, ou seja, um Graph cont�m o endere�o de um graph. */
typedef struct m_graph *M_Graph;


M_Graph M_GRAPHinit(int V);

static int **MATRIXint(int r, int c, int val);

void M_GRAPHinsertArc(M_Graph G, vertex v, vertex w);

void M_GRAPHremoveArc(M_Graph G, vertex v, vertex w);

void M_GRAPHshow(M_Graph G);

vertex *M_GRAPH_isSink(M_Graph G);

vertex *M_GRAPH_isSource(M_Graph G);

int M_GRAPHoutdeg(M_Graph G, vertex v);

int M_GRAPHindeg(M_Graph G, vertex v);

M_Graph M_GRAPHreverse(M_Graph G);

int M_isTournament(M_Graph G);

int M_GRAPHisadj(M_Graph G, vertex v, vertex w);

M_Graph M_GRAPHcomplement(M_Graph G);

// Cria um grafo completo iniciando todos os valores
// da matriz como 1 exceto os da diagonal principal
// Complexidade O(n^2)
M_Graph M_GRAPHbuildComplete(int V);