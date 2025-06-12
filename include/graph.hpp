#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "listaAdjacencia.hpp"
#include "armazem.hpp"

class Grafo {
public:
    Grafo();
    ~Grafo();

    void InsereVertice();
    void InsereAresta(int v, int w);  

    int QuantidadeVertices();
    int QuantidadeArestas();

    int GrauMinimo();
    int GrauMaximo();

    void ImprimeVizinhos(int v);
    ListaEncadeada<Armazem> BFS(Pacote& p);

private:
    ListaAdjacencia vertices;  // Lista de adjacência
    friend class Transporte;
};

#endif
