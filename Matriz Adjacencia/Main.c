#include "Adj.h"
#include "busca.h"

int main(){
    char *str = "entradas.txt";
    graph G;
    vertex v1,v2;
    v1 = InitializeVertex(1);
    v2 = InitializeVertex(0);

    G = InitializeGraph(str);
    PrintMatrix(G);
    PrintGraph(G);

    BFS(G,v2);
    printf("\n\n");
    DFS(G);

    printf("\n\n");

}

