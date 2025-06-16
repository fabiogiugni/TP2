#ifndef FILA_HPP
#define FILA_HPP

#include <iostream>
#include "no.hpp"

template<typename T>
class Fila{
    public:
        Fila();
        ~Fila();
        void Enfileira(const T& valor);
        T Desenfileira();
        bool vazia() const;

    private:
        No<T>* primeiro;
        No<T>* ultimo;
    friend class Grafo;
};

#include "fila.tpp"

#endif
