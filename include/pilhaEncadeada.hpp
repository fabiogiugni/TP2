#ifndef PILHAENCADEADA_HPP
#define PILHAENCADEADA_HPP

#include "no.hpp"  // Incluir a estrutura No

template <typename T>  // Declaração de template
class PilhaEncadeada {
public:
    PilhaEncadeada();  // Construtor
    ~PilhaEncadeada();  // Destruidor

    void Empilha(const T& item);  // Empilha um item
    T Desempilha();  // Desempilha e retorna um item
    bool Vazio() const;  // Verifica se a pilha está vazia
    void Limpa();  // Limpa a pilha
    bool removePorId(int id);  // Remove um item da pilha pelo ID
    int Tamanho() const;  // Retorna o tamanho da pilha

private:
    No<T>* topo;  // Ponteiro para o topo da pilha
    int tamanho;  // Tamanho da pilha
};

#include "pilhaEncadeada.tpp"  // Incluir o arquivo de implementação de templates

#endif
