#ifndef __INC__
#define __INC__

#include <stdio.h>
#include <stdlib.h>

/*Estruturas*/
    typedef struct Graph *graph;
    typedef struct Vertex *vertex;

    struct  Vertex{
        int value;
    };
    struct Graph{
        int V;              // Número de Vértices
        int E;              //Número de Arestas
        vertex **inc;
    };
/*Fim Estruturas*/

/*Métodos*/
    vertex InitializeVertex(int value);
    graph InitializeGraph(char *adress);
    void GraphInsert(graph G, int aresta, int v1, int v2); 

    void PrintMatrix(graph G);
    void PrintGraph(graph G);
/*Fim métodos*/

/*Implementações*/
    
    vertex InitializeVertex(int value){
        vertex aux = malloc(sizeof(vertex));
        aux->value = value;
        return aux;
    }

    graph InitializeGraph(char *adrees){
        FILE  *arq;
        int V;                                                  //Número de Vértices
        int E;                                                  //Número de arestas
        int inci1 = 0, inci2=0;                                 //Variáveis auxiliares para leitura de arq
        int numAresta = 0;
        arq = fopen(adrees,"r");

        /*Verificando se foi possível abrir o arquivo*/
        if (arq == NULL){ printf("Erro: Nao foi possivel abrir o arquivo"); return NULL;}
        
        fscanf(arq,"%d" "%d",&V,&E);                            //Lendo o número de vértices e arestas

        graph G = malloc(sizeof(graph));
        G->V = V;                                            
        G->E = E;
        G->inc = (vertex **)calloc(V,sizeof(vertex));
        for(int i = 0; i < V; i++)
            G->inc[i] = (vertex *)calloc(E,sizeof(vertex));

        for(int i = 0; i < V; i++)
            for(int j = 0; j < E; j++)
                G->inc[i][j] = InitializeVertex(0);             //Atribuindo valores default a matriz

        while (!feof(arq)){                                     //Leitura dos demais dados do arquivo
            if(inci1 >= V || inci2 >= V) break;
            if(numAresta >= E) break;

            fscanf(arq,"%d" "%d",&inci1, &inci2);
            printf("Valores lidos e q serao enviados %d %d\n",inci1,inci2);
            GraphInsert(G,numAresta,inci1,inci2);
            numAresta++;
            
        }
        fclose(arq);
            
        return G;
    }
    void GraphInsert(graph G, int aresta, int v1, int v2){
        vertex inci1 = InitializeVertex(v1);
        vertex inci2 = InitializeVertex(v2);

        if( (inci1->value >= G->V) || (inci2->value >= G->V) || (aresta >= G->E) ){ printf("\n\nErro, valores incompativeis.\n\n"); return; }
        
        if(G->inc[inci1->value][aresta]->value == 0){
            G->inc[inci1->value][aresta]->value = 1;
            G->inc[inci2->value][aresta]->value = 1;
        }

        free(inci1);
        free(inci2);
    }


    void PrintMatrix(graph G){
        printf("\n\n==================================================================================================");
        printf("\n\n\t\tMatriz de Incidencia\n\n");
        for(int i = 0; i < G->V; i++){
            if(i == 0){
                printf("\t    ");
                for(int j = 0; j < G->E; j++)
                    printf(" %d  ",j);
                printf("\n");
            }
            printf("\t");
            for(int j = 0; j < G->E; j++){
                if(j==0){
                    printf("%d-> ",i);
                }
                printf("[%d] ", G->inc[i][j]->value);
            }
            printf("\n");
        }
        printf("\n==================================================================================================\n");
        
 
    }
    void PrintGraph(graph G){
        printf("\n\n==================================================================================================");
        printf("\n\n\t\t\tVertices e Arestas\n\n");
        printf("\tInformacoes do Grafo:");
        printf("  Numero de vertices: %d", G->V);
        printf("  Numero de arestas: %d",G->E);
        printf("\n\n\tVertice->arestas:\n");
        for(int i = 0; i < G->V; i++){
                printf("\n\t%d-> ",i);
            for(int j = 0; j < G->E; j++)
                if(G->inc[i][j]->value == 1)
                    printf("%d ",j);
        }
        printf("\n==================================================================================================\n");

    }
/*Fim Implementações*/


#endif