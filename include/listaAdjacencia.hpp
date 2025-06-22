#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP

#include "tadsAuxiliares.hpp"


class ListaAdjacencia{
    public:
        ListaAdjacencia();
        ListaAdjacencia(int vertices);
        ~ListaAdjacencia();
        void insereAresta(int v, int w);
        int grauMinimo();
        int grauMaximo();
        void imprimeVizinhos();
        void insereVertice();
    private:
        int numVertices;
        ListaEncadeada* listaAdj;

    friend class Grafo;
};

#endif