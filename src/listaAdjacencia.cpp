#include "listaAdjacencia.hpp"
#include <iostream>

// Construtor sem parâmetros
ListaAdjacencia::ListaAdjacencia() {
    listaAdj = new ListaEncadeada<Armazem*>[0];
    numVertices = 0;
}

// Construtor com número de vértices
ListaAdjacencia::ListaAdjacencia(int vertices) : numVertices(vertices) {
    if (numVertices < 0) {
        std::cout << "Erro: número de vértices inválido!" << std::endl;
        return;
    }
    listaAdj = new ListaEncadeada<Armazem*>[numVertices];
}

// Destruidor
ListaAdjacencia::~ListaAdjacencia() {
    for (int i = 0; i < numVertices; ++i) {
        listaAdj[i].limpa();  // Limpa os nós, mas não deleta os Armazéns (só os nós)
    }
    delete[] listaAdj;
}

// Insere aresta entre os vértices v e w
void ListaAdjacencia::insereAresta(int v, Armazem* armazemDestino) {
    listaAdj[v].insereFinal(armazemDestino);
}

// Retorna o grau mínimo dos vértices
int ListaAdjacencia::grauMinimo() {
    if (numVertices == 0) return 0;
    int min = listaAdj[0].getTamanho();
    for (int i = 1; i < numVertices; ++i) {
        int atual = listaAdj[i].getTamanho();
        if (atual < min)
            min = atual;
    }
    return min;
}

// Retorna o grau máximo dos vértices
int ListaAdjacencia::grauMaximo() {
    if (numVertices == 0) return 0;
    int max = listaAdj[0].getTamanho();
    for (int i = 1; i < numVertices; ++i) {
        int atual = listaAdj[i].getTamanho();
        if (atual > max)
            max = atual;
    }
    return max;
}

// Imprime os vizinhos de cada vértice
void ListaAdjacencia::imprimeVizinhos() {
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Vértice " << i << ": ";
        No<Armazem*>* atual = listaAdj[i].primeiro;
        while (atual != nullptr) {
            std::cout << atual->item->getId() << " ";
            atual = atual->prox;
        }
        std::cout << std::endl;
    }
}

// Insere um novo vértice
void ListaAdjacencia::insereVertice() {
    ListaEncadeada<Armazem*>* novaListaAdj = new ListaEncadeada<Armazem*>[numVertices + 1];

    for (int i = 0; i < numVertices; i++) {
        novaListaAdj[i] = listaAdj[i];
    }

    delete[] listaAdj;
    listaAdj = novaListaAdj;
    ++numVertices;
}

// Insere pacote em um armazém baseado na origem
void ListaAdjacencia::inserePacote(Pacote* p) {
    Armazem* armazemDestino = listaAdj[p->getOrigem()].primeiro->item;
    armazemDestino->inserePacote(*p);
}