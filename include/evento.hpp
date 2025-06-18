#ifndef EVENTO_HPP
#define EVENTO_HPP

#include "pacote.hpp"

class Pacote;

struct Evento{
    int tempoEvento;
    int tipoEvento; //1-pacote 2 - transporte
    Pacote* p;//infos sobre origem e destino
    std::string descricao;
};

#endif