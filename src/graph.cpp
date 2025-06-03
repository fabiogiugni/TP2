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

void Grafo::BFS(int inicio) {
    int n = vertices.numVertices;

    // Inicializa visitados e distâncias
    bool* visitado = new bool[n];
    int* distancia = new int[n];

    for (int i = 0; i < n; ++i) {
        visitado[i] = false;
        distancia[i] = -1; // -1 indica vértice ainda não alcançado
    }

    Fila fila;
    visitado[inicio] = true;
    distancia[inicio] = 0;
    fila.enfileira(inicio);

    while (!fila.vazia()) {
        int v = fila.desenfileira();
        std::cout << "Visitando vértice " << v << ", distância = " << distancia[v] << std::endl;

        No* atual = vertices.listaAdj[v].primeiro;
        while (atual != nullptr) {
            int w = atual->item;
            if (!visitado[w]) {
                visitado[w] = true;
                distancia[w] = distancia[v] + 1;
                fila.enfileira(w);
            }
            atual = atual->prox;
        }
    }

    delete[] visitado;
    delete[] distancia;
}
