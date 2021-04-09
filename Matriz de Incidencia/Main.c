#include "Inc.h"
#include "Buscas.h"


int main(){
    char *str = "input.txt";
    graph G;

    G = InitializeGraph(str);
    PrintMatrix(G);
    PrintGraph(G);

    vertex v1 = InitializeVertex(0);
    BFS(G,v1);
    printf("\n\n");
    DFS(G);

    printf("\n\n");
    
}

