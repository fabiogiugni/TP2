#ifndef LISTAENCADEADA_HPP
#define LISTAENCADEADA_HPP

#include <iostream>
#include "listaEncadeada.tpp"

template <typename T>
struct No{
    T item;
    No<T>* prox;
};

template <typename T>
class ListaEncadeada{
    public:
        ListaEncadeada();
        ~ListaEncadeada();
    
        void insereInicio(const T& item);
        void insereFinal(const T& item);
        void imprime() const;
        int getTamanho() const;
    
    private:
        No<T> *primeiro;
        No<T> *ultimo;
        int tamanho;
    friend class Pacote;
    friend class ListaAdjacencia;
    friend class Grafo;
    friend class Armazem;
};

#endif