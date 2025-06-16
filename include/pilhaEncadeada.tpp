#ifndef PILHAENCADEADA_TPP
#define PILHAENCADEADA_TPP

#include "pilhaEncadeada.hpp"
#include <stdexcept>  // Para lançar exceções

// Construtor
template <typename T>
PilhaEncadeada<T>::PilhaEncadeada() : topo(nullptr), tamanho(0) {}

// Destruidor
template <typename T>
PilhaEncadeada<T>::~PilhaEncadeada() {
    Limpa();
}

// Empilha um item
template <typename T>
void PilhaEncadeada<T>::Empilha(const T& item) {
    No<T>* novo = new No<T>;  // Cria um novo nó
    novo->item = item;  // Atribui o item
    novo->prox = topo;  // O próximo do nó é o topo atual
    topo = novo;  // O topo é agora o novo nó
    tamanho++;  // Aumenta o tamanho
}

// Desempilha e retorna um item
template <typename T>
T PilhaEncadeada<T>::Desempilha() {
    if (Vazio()) {
        throw std::runtime_error("Erro: tentativa de desempilhar de uma pilha vazia.");
    }

    No<T>* temp = topo;  // Salva o topo da pilha
    T itemRemovido = temp->item;  // Salva o item removido
    topo = topo->prox;  // O topo passa a ser o próximo nó
    delete temp;  // Deleta o nó antigo
    tamanho--;  // Diminui o tamanho
    return itemRemovido;  // Retorna o item removido
}

// Verifica se a pilha está vazia
template <typename T>
bool PilhaEncadeada<T>::Vazio() const {
    return topo == nullptr;  // Se topo é nulo, a pilha está vazia
}

// Limpa a pilha (desempilha todos os itens)
template <typename T>
void PilhaEncadeada<T>::Limpa() {
    while (!Vazio()) {
        Desempilha();  // Desempilha até a pilha ficar vazia
    }
}

// Remove um item da pilha pelo ID
template <typename T>
bool PilhaEncadeada<T>::removePorId(int id) {
    PilhaEncadeada<T> auxiliar;  // Pilha auxiliar para armazenar os elementos temporariamente
    bool encontrado = false;

    // Desempilha até encontrar o item ou a pilha ficar vazia
    while (!Vazio()) {
        T itemAtual = Desempilha();
        if (itemAtual.getId() == id) {  // Se encontrar o item pelo ID
            encontrado = true;  // Marca como encontrado
            break;
        }
        auxiliar.Empilha(itemAtual);  // Caso contrário, empilha na pilha auxiliar
    }

    // Reempilha os itens da pilha auxiliar para a pilha original
    while (!auxiliar.Vazio()) {
        Empilha(auxiliar.Desempilha());
    }

    return encontrado;  // Retorna se o item foi encontrado
}

// Retorna o tamanho da pilha
template <typename T>
int PilhaEncadeada<T>::Tamanho() const {
    return tamanho;  // Retorna o tamanho atual da pilha
}

#endif
