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

void Grafo::inicializaVisitados() {
    liberaVisitados();
    visitado = new bool[vertices.numVertices];
    for (int i = 0; i < vertices.numVertices; ++i) {
        visitado[i] = false;
    }
}

void Grafo::liberaVisitados() {
    if (visitado != nullptr) {
        delete[] visitado;
        visitado = nullptr;
    }
}

void Grafo::BFS(int inicio) {
    inicializaVisitados();

    Fila fila;
    visitado[inicio] = true;
    fila.enfileira(inicio);

    while (!fila.vazia()) {
        int v = fila.desenfileira();
        std::cout << v << " ";

        No* atual = vertices.listaAdj[v].primeiro;
        while (atual != nullptr) {
            int w = atual->item;
            if (!visitado[w]) {
                visitado[w] = true;
                fila.enfileira(w);
            }
            atual = atual->prox;
        }
    }
    std::cout << std::endl;

    liberaVisitados();
}