#ifndef PILHAENCADEADAA_HPP
#define PILHAENCADEADAA_HPP

#include <iostream>
#include "pacote.hpp"

struct No {
    Pacote item;
    No* prox;
};


class PilhaEncadeada{
    public:
        PilhaEncadeada();
        ~PilhaEncadeada();
    
        void Empilha(Pacote item);
        Pacote Desempilha();
        void Limpa();
        bool Vazio();
    
    private:
        Pacote *topo;
        int tamanho;
};

#endif