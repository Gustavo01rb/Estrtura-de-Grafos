#include "Inc.h"


int main(){
    char *str = "entradas.txt";
    graph G;

    G = InitializeGraph(str);
    PrintMatrix(G);
    PrintGraph(G);

}

