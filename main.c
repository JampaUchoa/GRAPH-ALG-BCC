#include <stdio.h>
#include "GRAPH_LST.h"

int main(void) {

   Graph g = GRAPHinit(8);

   GRAPHinsertArc(g, 0, 4);
   GRAPHinsertArc(g, 4, 1);
   GRAPHinsertArc(g, 0, 3);
   GRAPHinsertArc(g, 3, 4);
   GRAPHinsertArc(g, 2, 3);
   GRAPHinsertArc(g, 3, 5);
   GRAPHinsertArc(g, 5, 2);
   GRAPHinsertArc(g, 5, 7);
   GRAPHinsertArc(g, 7, 6);
   GRAPHinsertArc(g, 6, 5);
   GRAPHinsertArc(g, 5, 6);
   GRAPHinsertArc(g, 3, 1);


   GRAPHshow(g);
   int *v = GRAPH_isSource2(g);
   
   GRAPHremoveArc(g,3,5);
   GRAPHremoveArc(g,4,1);
   //GRAPHshow(g);
   //vertex *v = GRAPH_isSource(g);

   for(int i = 0; i < g->V; i++)
      printf("%d ", v[i]);


  printf("\n");
  // Graph h = GRAPHcomplement(g);

  // GRAPHshow(h);


  return 0;
}