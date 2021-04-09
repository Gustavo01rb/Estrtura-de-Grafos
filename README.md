<h1> Estruturas de Grafos e Métodos de Busca </h1>

<p align="right">Gustavo Rodrigues Barcelos</p>

<h2>Introdução</h2>
<p>A atividade da disciplina: Algoritmos e estrutura de dados II tem como objetivo implementar as estruturas de grafos aprendidas em aula, sendo elas: Listas de Adjacência, Matriz de Adjacência e Matriz de Incidência. Para realização dessa atividade foi disponilizado a implentação do código: "Lista de Adjacência", a fim de servir como base de estudo e referência para implementação dos demais.</p>

<h3>Breve resumo da teoria de grafos:<a href="#wiki"><sup> [ 1 ]</sup></a></h3>
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

<h2>Estruturas de Grafos</h2>
<p>Em computação os grafos podem ser representados de diversas formas, nesse tópico será abordado somente as estruturas implementadas: Matriz de Adjacência e Matriz de Incidência</p>
<h3>Matriz de Adjacência</h3>
<p>Esse tipo de representação consiste em uma matriz N x N ( ADJ[N][N] ), na qual N é o número de vértices do grafo. As posições (i,j) da matriz representam se há ou não ligação entre os vétices indicados. Suponha que exista um grafo G, tal que G contenha pelo menos dois ou mais vértices, um vértice X(origem) e um vértice Y(destino), caso o valor contido na matirz ADJ na posição: ADJ[X][Y] for igual a 1, significa há uma aresta que parte de X e incide em Y.</p>

<h4>Inputs</h4>
<p>A pasta: <i>Matriz de Adjacencia</i> contém um arquivo nomeado de <i>"input.txt"</i>, que fornece os dados para formação de um grafo. As entradas são organizadas da seguinte forma:</p>
<table align="center">
    <thead>
        <th>Instrução</th>
        <th>Representação</th>
    </thead>
    <tbody>
        <tr>
            <td>A primeira linha indica o número de vértices do grafo</td>
            <td>  <img width="500" src="Imagens/Adj-Vertice.png" />  </td>
        </tr>
        <tr>
            <td>As demais linhas indicam os vértices e seus vértices adjacentes, começando pelo vértice 0. A segunda linha representa o vértice 0, a terceira o vértice 1....</td>
            <td>  <img width="500" src="Imagens/Adj-Linhas.png" />  </td>
        </tr>
        <tr>
            <td>   
            </td>
        </tr>
    </tbody>
</table>

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












<h2>Referências</h2>
[1] <a id="wiki" href="https://pt.wikipedia.org/wiki/Teoria_dos_grafos#Hist%C3%B3rico">Wikipedia</a><br/>