#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP

#include "armazem.hpp"
#include "listaEncadeada.hpp"


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
        void inserePacote(const Pacote& p);
    private:
        int numVertices;
        ListaEncadeada<int>* listaAdj;
        Armazem arm;
    friend class Fila;
    friend class Grafo;
    friend class Armazem;
};

#endif