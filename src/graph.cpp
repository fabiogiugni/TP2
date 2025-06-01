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