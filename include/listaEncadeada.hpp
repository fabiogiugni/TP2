#ifndef LISTAENCADEADA_HPP
#define LISTAENCADEADA_HPP

#include <iostream>

template <typename T>
struct No{
    T item;
    No<T>* prox;
};

class ListaEncadeada{
    public:
        ListaEncadeada();
        ~ListaEncadeada();
    
        void insereInicio(const T& item);
        void insereFinal(const T& item);
        void imprime();
    
    private:
        No<T> *primeiro;
        No<T> *ultimo;
        int tamanho;
    friend class Pacote;
    friend class ListaAdjacencia;
    friend class Grafo;
    friend class Armazem;
};

#include "listaEncadeada.tpp"
#endif