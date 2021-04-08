#ifndef __BUSCA__
#define __BUSCA__

#include "Adj.h"

/*Estrutura Base de Filas*/
    typedef struct TipoItem Item;
    typedef struct TipoFila Fila;

    struct TipoItem{
        int data;
        Item *prox;
    };
    struct TipoFila{
        Item *head;
        Item *tail;
        int size;
    };
/*Fim Estrutura Base de Filas*/

/*Funções*/
    //Estrutura de Fila
    Fila* FFVazia();
    void Queue(Fila *f, int vertex);
    Item* Dequeue(Fila *f);

    //BFS
    void BFS(graph G, vertex v);

/* Fim Funções*/



/*Estruturas de fila*/
    Fila* FFVazia(){
        Fila *f = (Fila*) malloc(sizeof(Fila));
        f->head = NULL;
        f->tail = NULL;
        return f;
    }

    void Queue(Fila *f, int vertex){
        Item *d = (Item *) malloc (sizeof(Item));
        d->data = vertex;
        d->prox = NULL;

        if(f->head == NULL){
            f->head = d;
            f->tail = d;
        }else{
            f->tail->prox = d;
            f->tail = d;
        }

        f->size ++;
    }

    Item* Dequeue(Fila *f){
        Item *aux;

        if(f->head == NULL)
            return NULL;

        aux = f->head;
        f->head = f->head->prox;
        f->size --;

        return aux;
    }
/*Fim Estrutura de Fila */

void BFS(graph G, vertex v){
    int cor[G->V];          // -1 = Preto, 0 = Branco, 1 = Cinza
    int d[G->V];
    int pi[G->V];
    Fila *f =FFVazia();

    for(int i = 0; i < G->V; i++)
        if(i != v->value){
            cor[i] = 0;
            d[i] = -1;      //Infinito
            pi[i] = -1;
        }
    cor[v->value] = 1;
    d[v->value] = 0;
    pi[v->value] = -1;

    Queue(f,v->value);

    while(f->size > 0){
        Item *aux = Dequeue(f);
        for(int i = 0; i < G->V; i++){
            if(G->adj[aux->data][i]->value == 1)
                if(cor[i] == 0){
                    cor[i] = 1;
                    d[i] = d[aux->data]+1;
                    pi[i] = aux->data;
                    Queue(f,i);
                }
        }
        cor[aux->data] = -1;
        printf("Vertex:%d\n", aux->data);
    }
}



#endif