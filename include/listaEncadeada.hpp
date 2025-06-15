#ifndef LISTAENCADEADA_HPP
#define LISTAENCADEADA_HPP

#include <iostream>

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
        T getPrimeiro() const;
        void removeInicio();

    
    private:
        No<T> *primeiro;
        No<T> *ultimo;
        int tamanho;
    friend class Pacote;
    friend class ListaAdjacencia;
    friend class Grafo;
    friend class Armazem;
    friend class Transporte;
};

#endif