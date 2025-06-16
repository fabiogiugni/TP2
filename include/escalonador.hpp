#ifndef ESCALONADOR_HPP
#define ESCALONADOR_HPP

#include "pacote.hpp"
#include "armazem.hpp"
#include "transporte.hpp"
#include "evento.hpp"
#include "heap.hpp"
#include <string>

class Escalonador {
public:
    Escalonador(int tempo);
    ~Escalonador();

    void escalonarTransporte(int tempoEvento, int origem, int destino);
    void escalonarChegada(int tempoEvento, int origem, int destino);
    void executarTransportes();

private:
    Heap heapEventos;  // Min-heap que armazena eventos
    int relogioGlobal; // Relógio do sistema
    void processarTransporte(Evento& evento);
    void processarChegada(Evento& evento);
    bool condicaoDeTermino; // Condição de término do sistema
};

#endif
