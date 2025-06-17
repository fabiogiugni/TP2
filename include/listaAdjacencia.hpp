#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP

#include "listaEncadeada.hpp"
#include "pacote.hpp"
#include "armazem.hpp"

class ListaAdjacencia {
public:
    ListaAdjacencia();
    ListaAdjacencia(int vertices);
    ~ListaAdjacencia();

    void insereAresta(int v, Armazem* armazemDestino);
    int grauMinimo();
    int grauMaximo();
    void imprimeVizinhos();
    void insereVertice();  // Adiciona um novo vértice
    void inserePacote(Pacote* p);

private:
    int numVertices;
    ListaEncadeada<Armazem*>* listaAdj;  // Agora armazena ponteiros para Armazem

    friend class Fila<Pacote>;
    friend class Grafo;
    friend class Armazem;
    friend class Transporte;
    friend class Escalonador;
};

#endif
