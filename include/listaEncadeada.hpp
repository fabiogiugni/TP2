#ifndef LISTAENCADEADA_HPP
#define LISTAENCADEADA_HPP

#include <iostream>

struct No{
    int item;
    No* prox;
};

class ListaEncadeada{
    public:
        ListaEncadeada();
        ~ListaEncadeada();
    
        void insereInicio(int item);
        void insereFinal(int item);
        void imprime();
    
    private:
        No *primeiro;
        No *ultimo;
        int tamanho;
    friend class ListaAdjacencia;
    friend class Grafo;
};

#endif