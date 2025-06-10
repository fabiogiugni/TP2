#include "listaAdjacencia.hpp"

ListaAdjacencia::ListaAdjacencia(){
    listaAdj = new ListaEncadeada<int>[0];
}

ListaAdjacencia::ListaAdjacencia(int vertices) : numVertices(vertices){
    listaAdj = new ListaEncadeada<int>[numVertices];
}

ListaAdjacencia::~ListaAdjacencia(){
    delete[] listaAdj;
}

void ListaAdjacencia::insereAresta(int v, int w){
    listaAdj[v].insereFinal(w);
}

int ListaAdjacencia::grauMinimo(){
    int min = listaAdj[0].tamanho;
    int atual=0;
    for(int i=1; i<numVertices;++i){
        atual = listaAdj[i].tamanho;
        if(min>atual)
        min = atual;
    }
    return min;
}

int ListaAdjacencia::grauMaximo(){
    int max = listaAdj[0].tamanho;
    int atual=0;
    for(int i=1; i<numVertices;++i){
        atual = listaAdj[i].tamanho;
        if(max<atual)
        max = atual;
    }
    return max;
}

void ListaAdjacencia::imprimeVizinhos(){
    for (int i = 0; i < numVertices; i++){
        std::cout << "Vértice " << i << ": ";
        listaAdj[i].imprime();
    }
}

void ListaAdjacencia::insereVertice(){
    // Aloca novo array com tamanho maior
    ListaEncadeada<int> *novaListaAdj = new ListaEncadeada<int>[numVertices + 1];

    // Copia as listas de adjacência antigas para o novo array
    for (int i = 0; i < numVertices; i++){
        novaListaAdj[i] = listaAdj[i];
    }

    // Deleta o array antigo
    delete[] listaAdj;

    // Atualiza o ponteiro adjList para o novo array e incrementa numVertices
    listaAdj = novaListaAdj;
    ++numVertices;
}