#ifndef EVENTO_HPP
#define EVENTO_HPP

#include "pacote.hpp"

struct Evento{
    int tempoEvento;
    int tipoEvento;
    Pacote* p;
    std::string descricao; //armazenado/removido/em transito
};

#endif