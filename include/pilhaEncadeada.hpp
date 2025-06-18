#ifndef PILHAENCADEADA_HPP
#define PILHAENCADEADA_HPP

#include <iostream>
#include "listaEncadeada.hpp"

class PilhaEncadeada {
public:
    PilhaEncadeada();  // Construtor
    ~PilhaEncadeada();  // Destruidor

    void Empilha(int item);  // Empilha um item
    int Desempilha();  // Desempilha e retorna um item
    bool Vazio() const;  // Verifica se a pilha está vazia
    void Limpa();  // Limpa a pilha
    bool removePorId(int id);  // Remove um item da pilha pelo ID
    int Tamanho() const;  // Retorna o tamanho da pilha
    void imprime() const;  // Imprime todos os itens da pilha

private:
    No* topo;  // Ponteiro para o topo da pilha
    int tamanho;  // Tamanho da pilha
};

#endif
