#ifndef ESCALONADOR_HPP
#define ESCALONADOR_HPP

#include "heap.hpp"
#include "graph.hpp"

//fila de prioridade

class Escalonador{
    public:
        Escalonador();
        ~Escalonador();
        void InsereVertice();
    private:
        int tempoAtual;
        Grafo mapa;
};

#endif