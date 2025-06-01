#ifndef PACOTE_HPP
#define PACOTE_HPP

#include <iostream>

struct Pacote {
    int item;
    Pacote *prox;
};

class PacoteRota {
    public:
        PacoteRota();
        ~PacoteRota();
    
        void insereInicio(int item);
        void insereFinal(int item);
        void imprime();
    
    private:
        No *primeiro;
        No *ultimo;
        int tamanhoRota;
    friend class Armazem;
};

#endif