#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "listaAdjacencia.hpp"
#include "fila.hpp"

class Grafo{
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
        void BFS(int inicio, int destino);
        
    private:
        ListaAdjacencia vertices;
};

#endif