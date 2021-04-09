<h1> Estruturas de Grafos e Métodos de Busca </h1>

<p align="right">Gustavo Rodrigues Barcelos</p>

<h2>Navegação Rápida</h2>
<a href="#introducao">1. Introdução</a><br/>
<a href="#resumo">1.1 Breve resumo da teoria de grafos</a><br/><br/>
<a href="#estrutura">2. Estruturas de Grafos</a><br/>
<a href="#adj">2.1 Matriz de Adjacência</a><br/>
<a href="#in-adj">2.1.1 Inputs</a><br/>
<a href="#cod-adj">2.1.2 Codificação</a><br/>
<a href="#ex-adj">2.1.3 Execução</a><br/>
<a href="#inc">2.2 Matriz de Incidência</a><br/>
<a href="#in-inc">2.2.1 Inputs</a><br/>
<a href="#cod-inc">2.2.2 Codificação</a><br/>
<a href="#ex-inc">2.2.3 Execução</a><br/>






<h2 id="introducao">1. Introdução</h2>
<p>A atividade da disciplina: Algoritmos e estrutura de dados II tem como objetivo implementar as estruturas de grafos aprendidas em aula, sendo elas: Listas de Adjacência, Matriz de Adjacência e Matriz de Incidência. Para realização dessa atividade foi disponilizado a implentação do código: "Lista de Adjacência", a fim de servir como base de estudo e referência para implementação dos demais.</p>

<h3 id="resumo">1.1 Breve resumo da teoria de grafos:<a href="#wiki"><sup> [ 1 ]</sup></a></h3>
<p>A teoria dos grafos é um ramo da matemática que estuda as relações entre os objetos de um determinado conjunto. Para tal são empregadas estruturas chamadas de grafos, G(V,E), onde V é um conjunto não vazio de objetos denominados vértices (ou nós) e E (do inglês edges - arestas) é um subconjunto de pares não ordenados de V.</p>
<p>As aplicações relacionadas a teoria de grafos são diversas e estão presentes em basicamente todos os lugares, grafos estão presentes em aparelhos GPS, nos diretórios de um computador, em redes sociais, em um mapa rodoviário, um sistema de distribuição de água ....</p>
<p>Representação Visual:</p>
<p align="center">
    <a href="http://danielamaral.wikidot.com/introducao-a-teoria-dos-grafos">
        <img src="Imagens/Introdução-grafo1.png" />
    </a>
</p>
<p>A imagem acima representa um grafo G(6,7). 6 Vértices e 7 arestas</p>

<br/>

<h2 id="estrutura">2. Estruturas de Grafos</h2>
<p>Em computação os grafos podem ser representados de diversas formas, nesse tópico será abordado somente as estruturas implementadas: Matriz de Adjacência e Matriz de Incidência</p>
<h3 id="adj">2.1 Matriz de Adjacência</h3>
<p>Esse tipo de representação consiste em uma matriz N x N ( ADJ[N][N] ), na qual N é o número de vértices do grafo. As posições (i,j) da matriz representam se há ou não ligação entre os vétices indicados. Suponha que exista um grafo G, tal que G contenha pelo menos dois ou mais vértices, um vértice X(origem) e um vértice Y(destino), caso o valor contido na matirz ADJ na posição: ADJ[X][Y] for igual a 1, significa há uma aresta que parte de X e incide em Y.</p>

<h4 id="in-adj">2.1.1 Inputs</h4>
<p>A pasta: <i>Matriz de Adjacencia</i> contém um arquivo nomeado de <i>"input.txt"</i>, que fornece os dados para formação de um grafo. As entradas são organizadas da seguinte forma:</p>
<table align="center">
    <thead>
        <th>Instrução</th>
        <th>Representação</th>
    </thead>
    <tbody>
        <tr>
            <td>A primeira linha indica o número de vértices do grafo</td>
            <td>  <img width="500"  src="Imagens/Adj-Vertice.png" />  </td>
        </tr>
        <tr>
            <td>As demais linhas indicam os vértices e seus vértices adjacentes, começando pelo vértice 0. A segunda linha representa o vértice 0, a terceira o vértice 1....</td>
            <td>  <img width="500"  src="Imagens/Adj-Linhas.png" />  </td>
        </tr>
        <tr>
            <td>   
                As linhas são compostas por colunas e cada coluna indica o vértice adjacente.
            </td>
            <td>  <img width="500"  src="Imagens/Adj-linhas.png" />  </td>
        </tr>
        <tr>
            <td>
                Todas as linhas são encerradas com o valor -1, esse valor não é computado e serve apenas como referência.
            </td>
            <td>  <img width="500"  src="Imagens/Adj-1.png" />  </td>
        </tr>
    </tbody>
</table>

<ul>
<li>
<p>Conteúdo armazenado em <i>input.txt:</i></p>

~~~C
8
1 2 -1
0 3 -1
0 4 5 -1
1 -1
2 5 6 -1
2 4 6 7 -1
4 5 7 -1
5 6
~~~

</li>
<li>
<p>Representação visual de <i>input.txt</i>:</p>
<p align="center">
    <img src="Imagens/ADJ-grafo.png"
</p>
</li>
</ul>

<h4 id="cod-adj">2.1.2 Codificação</h4>

<p>Os códigos referentes a matriz de adjacência se encontram em: <i>Matriz Adjacencia/Adj.h</i></p>

<p>A representação dessa estrutura na linguagem C se deu da seguinte forma: </p>

~~~C
struct  Vertex{             //Estrutura que representa um Vértice
    int value;
};
struct Graph{
    int V;                  //Número de Vértices
    int E;                  //Número de Arestas
    vertex **adj;           //Matriz de Adjacência
};
~~~

<p>A função <i>InitializeGraph(char *adrees)</i>, sofreu algumas pequenas modificações comparadas com a Lista de adjacência. Na estrutura em si, a principal diferença foi no caminhamento entre os vértices adjacentes, o código agora 'caminha' na matriz de adjcência buscando os índices do vértices adjacentes. Além disso a leitura e inserção do arquivo input ocorre nessa etapa.</p>

~~~C
vertex InitializeVertex(int value){
    vertex aux = malloc(sizeof(vertex));
    aux->value = value;
    return aux;
}

graph InitializeGraph(char *adrees){
    FILE  *arq;
    int V;                                                  //Número de Vértices
    int origem = 0, destino;                                //Variáveis auxiliares para leitura de arq
    arq = fopen(adrees,"r");

    /*Verificando se foi possível abrir o arquivo*/
    if (arq == NULL){ printf("Erro: Nao foi possivel abrir o arquivo"); return NULL;}
    
    fscanf(arq,"%d",&V);                                    //Lendo o número de vértices

    graph G = malloc(sizeof(graph));
    G->V = V;                                            
    G->E = 0;
    G->adj = (vertex **)calloc(V,sizeof(vertex));
    for(int i = 0; i < V; i++)
        G->adj[i] = (vertex *)calloc(V,sizeof(vertex));

    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            G->adj[i][j] = InitializeVertex(0);             //Atribuindo valores default a matriz

    while (!feof(arq)){                                     //Leitura dos demais dados do arquivo
        if(origem >= V) break;

        fscanf(arq,"%d",&destino);
        if(destino != -1)
            GraphInsert(G,origem,destino);
        else
            origem++;
        
    }
    fclose(arq);
        
    return G;
}
~~~

<p>A função: <i>GraphInsert(graph G, int v1, int v2)</i> insere as arestas ou conexões entre os vértices do grafo. Essa função recebe como parâmetro 2 índices de vértices, v1 indicando a origem e v2 o destino. Se os valores de v1 e v2 forem válidos a matriz ADJ[v1][v2] recebe 1.</p>

~~~C
void GraphInsert(graph G, int v1, int v2){
    vertex origem = InitializeVertex(v1);
    vertex destino = InitializeVertex(v2);

    if( (origem->value >= G->V) || (destino->value >= G->V) ){ printf("\n\nErro, valores incompativeis.\n\n"); return; }
    
    if(G->adj[origem->value][destino->value]->value == 0){
        G->adj[origem->value][destino->value]->value = 1;
        G->E++;
    }

    free(origem);
    free(destino);
}
~~~

<p>Por fim, as funções: <i>PrintMatrix(graph G) e PrintGraph(graph G)</i> fornecem representação dos resultados obtidos:</p>

~~~C
void PrintMatrix(graph G){
    printf("\n\n==================================================================================================");
    printf("\n\n\tMatriz de Adjacencia:\n\n");
    for(int i = 0; i < G->V; i++){
        if(i == 0){
            printf("\t\t    ");
            for(int j = 0; j < G->V; j++)
                printf(" %d  ",j);
            printf("\n");
        }
        printf("\t\t");
        for(int j = 0; j < G->V; j++){
            if(j==0){
                printf("%d-> ",i);
            }
            printf("[%d] ", G->adj[i][j]->value);
        }
        printf("\n");
    }
}
void PrintGraph(graph G){
    printf("\n\n\tVertices e Arestas:\n");
    for(int i = 0; i < G->V; i++){
            printf("\n\t\t%d-> ",i);
        for(int j = 0; j < G->V; j++)
            if(G->adj[i][j]->value == 1)
                printf("%d ",j);
    }
    printf("\n\n\tInformacoes do Grafo:");
    printf("\n\n\t\tNumero de vertices: %d", G->V);
    printf("  Numero de arestas: %d",G->E);
    printf("\n==================================================================================================\n");

}
~~~

<h4 id="ex-adj">2.1.3 Execução</h4>
<p>Ao compilar e executar o código de Matriz Adjacencia epesra-se com a leitura de "input.txt" obtem-se o seguinte resultado:</p>
<p align="center">
    <img src="Imagens/ADJ-resultados.png" />
</p>


<h3 id="inc">2.2 Matriz de Incidência</h3>
<p>Esse tipo de representação consiste em uma matriz N x M (INC[N][M]), na qual N é o número de vértices e M o número de arestas do grafo. As posições (i,j) da matriz representa se há ou não incidencia da aresta no vétice indicado. Diferente da matriz de ajacência as conxões na matriz de incidência são representadas pelas colunas. Suponha que exista um grafo G, tal que G contenha pelo menos dois ou mais vértices, um vértice X(origem) e um vértice Y(destino), caso haja uma aresta J que parte de X e incide em Y a representação na matriz será indicada da seguinte forma: INC[X][J] = -1 e INC[Y][J] = 1. Dessa forma cada coluna contem somente no máximo 2 valores, -1 para idicar a origem da aresta e 1 para indicar o destino.</p>


<h4 id="in-inc">2.2.1 Inputs</h4>
<p>A pasta: <i>Matriz de Incidencia</i> contém um arquivo nomeado de <i>"input.txt"</i>, que fornece os dados para formação de um grafo. As entradas são organizadas da seguinte forma:</p>
<table align="center">
    <thead>
        <th>Instrução</th>
        <th>Representação</th>
    </thead>
    <tbody>
        <tr>
            <td>A primeira linha indica o número de vértices do grafo seguido do número de arestas</td>
            <td>  <img width="500"  src="Imagens/INC-Vertice.png" />  </td>
        </tr>
        <tr>
            <td>As demais linhas indicam as arestas do grafo sendo o primeiro número o vértice de origem e o segundo o vértice de destino.</td>
            <td>  <img width="500" src="Imagens/INC-arestas.png" />  </td>
        </tr>
    </tbody>
</table>

<ul>
<li>
<p>Conteúdo armazenado em <i>input.txt:</i></p>

~~~C
8 20
0 1
0 2
1 3
1 0
2 0
2 4
2 5
3 1
4 2
4 5
4 6
5 2
5 4
5 6
5 7 
6 4
6 5
6 7
7 5
7 6
~~~

</li>
<li>
<p>Representação visual de <i>input.txt</i>:</p>
<p align="center">
    <img src="Imagens/ADJ-grafo.png"
</p>
</li>
</ul>

<h4 id="cod-inc">2.2.2 Codificação</h4>

<p>Os códigos referentes a matriz de adjacência se encontram em: <i>Matriz Adjacencia/Adj.h</i></p>

<p>A representação dessa estrutura na linguagem C se deu da seguinte forma: </p>

~~~C
struct  Vertex{             //Estrutura que representa um Vértice
    int value;
};
struct Graph{
    int V;                  //Número de Vértices
    int E;                  //Número de Arestas
    vertex **inc;           //Matriz de Incidência
};
~~~

<p>A função <i>InitializeGraph(char *adrees)</i>, sofreu algumas pequenas modificações comparadas com a Lista de adjacência. Na estrutura em si, a principal diferença foi no caminhamento entre os vértices adjacentes, o código agora 'caminha' na matriz de incidência buscando arestas que partem de um vértice e incidem em outro, além de caminhar nas colunas também caminha nas linhas para achar o índice do vértice incidente. Além disso a leitura e inserção do arquivo input ocorre nessa etapa.</p>

~~~C
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
        GraphInsert(G,numAresta,inci1,inci2);
        numAresta++;
        
    }
    fclose(arq);
        
    return G;

}
~~~

<p>A função: <i>GraphInsert(graph G, int aresta, int v1, int v2)</i> insere as origens e destino das arestas do grafo. Suponha que que a aresta 00 tem origem no vértice 1 e destino no vértice 7. Sua representação na matriz(INC) será: INC[1][00] = -1 e INC[7][00] = 1.</p>

~~~C
void GraphInsert(graph G, int aresta, int v1, int v2){
    vertex inci1 = InitializeVertex(v1);
    vertex inci2 = InitializeVertex(v2);

    if( (inci1->value >= G->V) || (inci2->value >= G->V) || (aresta >= G->E) ){ printf("\n\nErro, valores incompativeis.\n\n"); return; }
    
    if(G->inc[inci1->value][aresta]->value == 0){
        G->inc[inci1->value][aresta]->value = -1;
        G->inc[inci2->value][aresta]->value = 1;
    }

    free(inci1);
    free(inci2);
}
~~~

<p>Por fim, as funções: <i>PrintMatrix(graph G) e PrintGraph(graph G)</i> fornecem representação dos resultados obtidos:</p>

~~~C
void PrintMatrix(graph G){
    printf("\n\n==================================================================================================");
    printf("\n\n\tMatriz de Incidencia:\n\n");
    for(int i = 0; i < G->V; i++){
        if(i == 0){
            printf("\t\t    ");
            for(int j = 0; j < G->E; j++)
                printf(" %.2d  ",j);
            printf("\n");
        }
        printf("\t\t");
        for(int j = 0; j < G->E; j++){
            if(j==0){
                printf("%d-> ",i);
            }
            if(G->inc[i][j]->value >= 0) printf("[%.2d] ", G->inc[i][j]->value);
            else printf("[%d] ", G->inc[i][j]->value);
             
        }
        printf("\n");
    }
}
void PrintGraph(graph G){
    printf("\n\n\tVertices e Arestas:\n");
    
    for(int i = 0; i < G->V; i++){
            printf("\n\t\t%d-> ",i);
        for(int j = 0; j < G->E; j++)
            if(G->inc[i][j]->value == -1)
                printf("%d ",j);
    }
    printf("\n\n\tInformacoes do Grafo:");
    printf("\n\n\t\tNumero de vertices: %d", G->V);
    printf("  Numero de arestas: %d",G->E);
    printf("\n==================================================================================================\n");

}
~~~

<h4 id="ex-inc">2.2.3 Execução</h4>
<p>Ao compilar e executar o código de Matriz Adjacencia epesra-se com a leitura de "input.txt" obtem-se o seguinte resultado:</p>
<p align="center">
    <img src="Imagens/INC-Resultado.png" />
</p>







<h2>Referências</h2>
[1] <a id="wiki" href="https://pt.wikipedia.org/wiki/Teoria_dos_grafos#Hist%C3%B3rico">Wikipedia</a><br/>