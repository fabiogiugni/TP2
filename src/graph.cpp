#include <iostream>
#include "graph.hpp"
#include "armazem.hpp"
#include "listaAdjacencia.hpp"

Grafo::Grafo(int numeroArmazens) : vertices(numeroArmazens), numeroArmazens(numeroArmazens) {
    armazens = new Armazem*[numeroArmazens];  // Aloca um vetor de ponteiros para Armazem
}

Grafo::~Grafo() {
    // Libera a memória alocada para os armazéns
    delete[] armazens;
}

void Grafo::InsereVertice(Armazem* armazem) {
    armazens[numeroArmazens - 1] = armazem;  // Coloca o ponteiro no índice apropriado
    numeroArmazens++;
}

void Grafo::InsereAresta(int v, Armazem* armazemDestino) {
    // Insere a aresta entre o vértice v e o armazém destino, passando o ponteiro para o armazém
    vertices.insereAresta(v, armazemDestino);  // Insere o ponteiro do armazém na lista de adjacência
}

int Grafo::QuantidadeVertices() {
    return vertices.numVertices;  // Retorna a quantidade de vértices (armazéns)
}

int Grafo::QuantidadeArestas() {
    int arestas = 0;
    for (int i = 0; i < vertices.numVertices; ++i) {
        arestas += vertices.listaAdj[i].tamanho;
    }
    return arestas / 2;  // Divide por 2 para não contar arestas duplicadas
}

int Grafo::GrauMinimo() {
    return vertices.grauMinimo();  // Chama a função da lista de adjacência para grau mínimo
}

int Grafo::GrauMaximo() {
    return vertices.grauMaximo();  // Chama a função da lista de adjacência para grau máximo
}

void Grafo::ImprimeVizinhos() {
    // Imprime os vizinhos de cada vértice (armazém)
    vertices.imprimeVizinhos();  // Chama a função de impressão de vizinhos da lista de adjacência
}

ListaEncadeada<Armazem*> Grafo::BFS(int origem, int destino) {
    int n = vertices.numVertices;

    bool* visitado = new bool[n];
    int* distancia = new int[n];
    int* predecessor = new int[n];

    for (int i = 0; i < n; ++i) {
        visitado[i] = false;
        distancia[i] = -1;
        predecessor[i] = -1;
    }

    Fila<int> fila;
    visitado[origem] = true;
    distancia[origem] = 0;
    fila.Enfileira(origem);

    while (!fila.vazia()) {
        int v = fila.Desenfileira();
        No<Armazem*>* atual = vertices.listaAdj[v].primeiro;

        while (atual != nullptr) {
            Armazem* w = atual->item;
            int idW = w->getId();
            if (!visitado[idW]) {
                visitado[idW] = true;
                distancia[idW] = distancia[v] + 1;
                predecessor[idW] = v;
                fila.Enfileira(idW);
            }
            atual = atual->prox;
        }
    }

    ListaEncadeada<Armazem*> rota;

    if (distancia[destino] == -1) {
        std::cout << "Destino " << destino << " não alcançável a partir de " << origem << "\n";
        delete[] visitado;
        delete[] distancia;
        delete[] predecessor;
        return rota;
    }

    for (int v = destino; v != -1; v = predecessor[v]) {
        Armazem* a = vertices.listaAdj[v].primeiro->item;
        rota.insereInicio(a);
    }

    delete[] visitado;
    delete[] distancia;
    delete[] predecessor;

    return rota;
}

