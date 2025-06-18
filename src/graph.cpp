#include <iostream>
#include "graph.hpp"

Grafo::Grafo(): vertices(0){}

Grafo::~Grafo() {}

void Grafo::InsereVertice(){
    vertices.insereVertice();
}

void Grafo::InsereAresta(int v, int w){
    vertices.insereAresta(v,w);
}

int Grafo::QuantidadeVertices(){
    return vertices.numVertices;
}

int Grafo::QuantidadeArestas(){
    int arestas = 0;
    for(int i=0 ; i < vertices.numVertices ; ++i){
        arestas+=vertices.listaAdj[i].tamanho;
    }
    return arestas/2;
}

int Grafo::GrauMinimo(){
    return vertices.grauMinimo();
}

int Grafo::GrauMaximo(){
    return vertices.grauMaximo();
}

void Grafo::ImprimeVizinhos(int v){
    vertices.listaAdj[v].imprime();
}

ListaEncadeada Grafo::BFS(int origem, int destino) {
    int n = vertices.numVertices;

    bool* visitado = new bool[n];
    int* distancia = new int[n];
    int* predecessor = new int[n];

    for (int i = 0; i < n; ++i) {
        visitado[i] = false;
        distancia[i] = -1;
        predecessor[i] = -1;
    }

    Fila fila;
    visitado[origem] = true;
    distancia[origem] = 0;
    fila.Enfileira(origem);

    while (!fila.vazia()) {
        int v = fila.Desenfileira();
        No* atual = vertices.listaAdj[v].primeiro;

        while (atual != nullptr) {
            int w = atual->item;
            if (!visitado[w]) {
                visitado[w] = true;
                distancia[w] = distancia[v] + 1;
                predecessor[w] = v;
                fila.Enfileira(w);
            }
            atual = atual->prox;
        }
    }

    ListaEncadeada rota;

    for (int v = destino; v != -1; v = predecessor[v]) {
        rota.insereInicio(v);  // Inserindo apenas o índice dos vértices
    }

    // Libera a memória alocada para visitado, distancia e predecessor
    delete[] visitado;
    delete[] distancia;
    delete[] predecessor;

    return rota;
}
