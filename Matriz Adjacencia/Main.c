#include "Adj.h"

void insere(graph G);

int main(){
    char *str = "entradas.txt";
    graph G;
    vertex v1,v2;
    v1 = InitializeVertex(1);
    v2 = InitializeVertex(0);

    G = InitializeGraph(str);
    PrintMatrix(G);
    PrintGraph(G);

}

void insere(graph G){
    GraphInsert(G,0,1);
}