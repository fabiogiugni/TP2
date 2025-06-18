#ifndef FILA_HPP
#define FILA_HPP

#include <iostream>
#include "listaEncadeada.hpp"

class Fila {
public:
    Fila();
    ~Fila();

    void Enfileira(int valor);
    int Desenfileira();
    bool vazia() const;

private:
    No* primeiro;
    No* ultimo;
};

#endif
