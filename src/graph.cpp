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

void Grafo::BFS(int inicio, int destino) {
    int n = vertices.numVertices;

    // Inicializa visitados, distâncias e predecessores
    bool* visitado = new bool[n];
    int* distancia = new int[n];
    int* predecessor = new int[n];  // Vetor para armazenar o caminho (predecessores)

    for (int i = 0; i < n; ++i) {
        visitado[i] = false;
        distancia[i] = -1;  // -1 significa não alcançado
        predecessor[i] = -1;  // -1 significa que não há predecessor
    }

    Fila<int> fila;
    visitado[inicio] = true;
    distancia[inicio] = 0;
    fila.Enfileira(inicio);

    while (!fila.vazia()) {
        int v = fila.Desenfileira();
        std::cout << "Visitando vértice " << v << ", distância = " << distancia[v] << std::endl;

        No<int>* atual = vertices.listaAdj[v].primeiro;
        while (atual != nullptr) {
            int w = atual->item;
            if (!visitado[w]) {
                visitado[w] = true;
                distancia[w] = distancia[v] + 1;
                predecessor[w] = v;  // Armazena de onde veio (v)
                fila.Enfileira(w);
            }
            atual = atual->prox;
        }
    }

    // Imprimir o caminho até o destino, se encontrado
    if (distancia[destino] != -1) {
        std::cout << "Caminho até o vértice " << destino << ":\n";
        int caminhoAtual = destino;
        while (caminhoAtual != -1) {
            std::cout << caminhoAtual << " <- ";
            caminhoAtual = predecessor[caminhoAtual];
        }
        std::cout << "Início\n";
    } else {
        std::cout << "Vértice " << destino << " não é alcançável a partir de " << inicio << std::endl;
    }

    delete[] visitado;
    delete[] distancia;
    delete[] predecessor;
}
