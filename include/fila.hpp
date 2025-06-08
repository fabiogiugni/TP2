#ifndef FILA_HPP
#define FILA_HPP

#include <iostream>

template<typename T>
struct NoFila{
    T item;
    NoFila* prox;
};

template<typename T>
class Fila{
    public:
        Fila();
        ~Fila();
        void Enfileira(const T& valor);
        T Desenfileira();
        bool vazia() const;

    private:
        NoFila<T>* primeiro;
        NoFila<T>* ultimo;
};

#include "fila.tpp"

#endif
