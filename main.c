#include <stdio.h>
#include "GRAPH_LST.h"
#include "GRAPH_MTX.h"

int main(void) {

    M_Graph g = M_GRAPHinit(8);

    M_GRAPHinsertArc(g, 0, 4);
    M_GRAPHinsertArc(g, 4, 1);
    M_GRAPHinsertArc(g, 0, 3);
    M_GRAPHinsertArc(g, 3, 4);
    M_GRAPHinsertArc(g, 2, 3);
    M_GRAPHinsertArc(g, 3, 5);
    M_GRAPHinsertArc(g, 5, 2);
    M_GRAPHinsertArc(g, 5, 7);
    M_GRAPHinsertArc(g, 7, 6);
    M_GRAPHinsertArc(g, 6, 5);
    M_GRAPHinsertArc(g, 5, 6);
    M_GRAPHinsertArc(g, 3, 1);


    M_GRAPHshow(g);
    int *v = M_GRAPH_isSource(g);

    M_GRAPHremoveArc(g, 3, 5);
    M_GRAPHremoveArc(g, 4, 1);
    //M_GRAPHshow(g);
    //vertex *v = M_GRAPH_isSource(g);

    for (int i = 0; i < g->V; i++)
        printf("%d ", v[i]);


    printf("\n");
    // Graph h = M_GRAPHcomplement(g);

    // M_GRAPHshow(h);


    return 0;
}