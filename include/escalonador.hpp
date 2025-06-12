#ifndef ESCALONADOR_HPP
#define ESCALONADOR_HPP

#include "heap.hpp"
#include "graph.hpp"
#include "evento.hpp"

//fila de prioridade

class Escalonador{
    public:
        Escalonador();
        ~Escalonador();
        void InsereVertice();
        void PostagemPacote(const Pacote&p);
    private:
        int tempoAtual;
};

#endif