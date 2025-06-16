#ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>
#include "evento.hpp"  // Incluindo o arquivo de evento

class Heap {
public:
    Heap(); 
    Heap(int maxsize);
    ~Heap();

    void Inserir(const Evento& e);  // Inserir um evento
    Evento Remover();               // Remover o evento com o menor tempo (mínimo)
    
    bool Vazio() const;

private:
    int GetAncestral(int posicao);
    int GetSucessorEsq(int posicao);
    int GetSucessorDir(int posicao);

    int tamanho;
    Evento* data;  // Agora armazenamos Evento em vez de int

    void HeapifyPorBaixo(int posicao);
    void HeapifyPorCima(int posicao);
};

#endif
