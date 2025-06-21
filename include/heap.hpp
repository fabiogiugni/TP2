#ifndef HEAP_HPP
#define HEAP_HPP
#include <iostream>

class Heap {

public:
    Heap();
    Heap(int maxsize);
    ~Heap();

    void Inserir(long long int x);  // Alterado para long long int
    long long int Remover();        // Alterado para long long int

    bool Vazio();

private:
    int GetAncestral(int posicao);
    int GetSucessorEsq(int posicao);
    int GetSucessorDir(int posicao);

    int tamanho;
    long long int* data;  // Alterado para long long int
    int capacidade;        // Declaração da variável capacidade

    void HeapifyPorBaixo(int posicao);
    void HeapifyPorCima(int posicao);
};

#endif
