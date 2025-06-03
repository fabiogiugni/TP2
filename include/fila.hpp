#ifndef FILA_HPP
#define FILA_HPP

#include <iostream>

struct NoFila{
    int item;
    NoFila*prox;
};

class Fila{
    public:
        Fila();
        ~Fila();
        void Enfileira(int valor);
        int Desenfileira();

    private:
        NoFila* primeiro;
        NoFila* ultimo;
};

#endif