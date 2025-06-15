#include <iostream>
#include "graph.hpp"

Grafo::Grafo() : vertices(0) {}

Grafo::~Grafo() {}

void Grafo::InsereVertice() {
    vertices.insereVertice();  // Insere um novo armazém na lista de adjacência
    // Agora você precisa associar os armazéns aos vértices
}

void Grafo::InsereAresta(int v, int w) {
    vertices.insereAresta(v, w);  // Insere um ponteiro para armazém na lista de adjacência
}

int Grafo::QuantidadeVertices() {
    return vertices.numVertices;
}

int Grafo::QuantidadeArestas() {
    int arestas = 0;
    for (int i = 0; i < vertices.numVertices; ++i) {
        arestas += vertices.listaAdj[i].tamanho;
    }
    return arestas / 2;
}

int Grafo::GrauMinimo() {
    return vertices.grauMinimo();
}

int Grafo::GrauMaximo() {
    return vertices.grauMaximo();
}

void Grafo::ImprimeVizinhos(int v) {
    // Agora os vizinhos são armazéns, então precisamos imprimir as informações dos armazéns
    vertices.listaAdj[v].imprime();
}


ListaEncadeada<Armazem> Grafo::BFS(int origem, int destino) {
    int n = vertices.numVertices;

    // Inicializa vetores auxiliares
    bool* visitado = new bool[n];
    int* distancia = new int[n];
    int* predecessor = new int[n];

    for (int i = 0; i < n; ++i) {
        visitado[i] = false;
        distancia[i] = -1;
        predecessor[i] = -1;
    }

    // Fila de BFS
    Fila<int> fila;
    visitado[origem] = true;
    distancia[origem] = 0;
    fila.Enfileira(origem);

    // Busca em largura
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

    ListaEncadeada<Armazem> rota;

    // Se destino não foi alcançado
    if (distancia[destino] == -1) {
        std::cout << "Destino " << destino << " não alcançável a partir de " << origem << "\n";
        delete[] visitado;
        delete[] distancia;
        delete[] predecessor;
        return rota;  // Vazio
    }

    // Reconstrói rota do destino até a origem usando predecessor[]
    for (int v = destino; v != -1; v = predecessor[v]) {
        Armazem* a = vertices.listaAdj[v].primeiro->item;  // Pegamos o primeiro da lista, que é o próprio vértice
        Armazem copia(*a);  // Fazemos cópia (pois a lista espera Armazem, não ponteiro)
        rota.insereInicio(copia);
    }

    delete[] visitado;
    delete[] distancia;
    delete[] predecessor;

    return rota;
}
