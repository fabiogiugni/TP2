#ifndef FILA_HPP
#define FILA_HPP

#include <iostream>

template<typename T>
struct No{
    T item;
    No<T>* prox;
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
        No<T>* primeiro;
        No<T>* ultimo;
    friend class Grafo;
};

#include "fila.tpp"

#endif
