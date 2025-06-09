#ifndef ESCALONADOR_HPP
#define ESCALONADOR_HPP

#include "heap.hpp"
#include "graph.hpp"

//fila de prioridade

class Escalonador{
    public:
        Escalonador();
        ~Escalonador();
    
    private:
        int tempoAtual;
        Grafo mapaArmazens;
};

#endif