#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "listaAdjacencia.hpp"
#include "armazem.hpp"

class Grafo {
public:
    Grafo(int numeroArmazens);
    ~Grafo();

    void InsereVertice(Armazem* armazem);  // Agora insere ponteiro para Armazem
    void InsereAresta(int v, Armazem* armazemDestino);  

    int QuantidadeVertices();
    int QuantidadeArestas();

    int GrauMinimo();
    int GrauMaximo();

    void ImprimeVizinhos();
    ListaEncadeada<Armazem*> BFS(int origem, int destino);

private:
    ListaAdjacencia vertices;  // Lista de adjacência
    Armazem** armazens;  // Agora é um vetor de ponteiros para Armazem
    int numeroArmazens;

    friend class Transporte;
    friend class Escalonador;
};


#endif
