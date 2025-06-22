#ifndef HEAP_HPP
#define HEAP_HPP
#include <iostream>

class Heap {

public:
    Heap();
    Heap(int maxsize);
    ~Heap();

    void Inserir(__uint128_t  x);  // Alterado para __uint128_t 
    __uint128_t  Remover();        // Alterado para __uint128_t 

    bool Vazio();

private:
    int GetAncestral(int posicao);
    int GetSucessorEsq(int posicao);
    int GetSucessorDir(int posicao);

    int tamanho;
    __uint128_t * data;  // Alterado para __uint128_t 
    int capacidade;        // Declaração da variável capacidade

    void HeapifyPorBaixo(int posicao);
    void HeapifyPorCima(int posicao);
};

#endif
