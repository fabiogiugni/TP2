#ifndef LISTAENCADEADA_TPP
#define LISTAENCADEADA_TPP

#include <iostream>
#include "listaEncadeada.hpp"

template<typename T>
ListaEncadeada<T>::ListaEncadeada() : primeiro(nullptr), ultimo(nullptr), tamanho(0) {}

template<typename T>
ListaEncadeada<T>::~ListaEncadeada() {
    while (primeiro != nullptr) {
        No<T>* temp = primeiro;
        primeiro = primeiro->prox;
        delete temp;
    }
}

template<typename T>
void ListaEncadeada<T>::insereInicio(const T& item) {
    No<T>* novo = new No<T>{item, primeiro};
    primeiro = novo;
    if (ultimo == nullptr) {
        ultimo = novo;
    }
    ++tamanho;
}

template<typename T>
void ListaEncadeada<T>::insereFinal(const T& item) {
    No<T>* nova = new No<T>{item, nullptr};
    if (ultimo != nullptr) {
        ultimo->prox = nova;
    } else {
        primeiro = nova;
    }
    ++tamanho;
    std::cout<<tamanho<<std::endl;
}

template<typename T>
void ListaEncadeada<T>::imprime() const {
    for (No<T>* atual = primeiro; atual != nullptr; atual = atual->prox) {
        std::cout << atual->item.getId() << " ";  // Acessa diretamente o ID de Armazem
    }
    std::cout << std::endl;
}


template<typename T>
int ListaEncadeada<T>::getTamanho() const {
    return tamanho;
}

template <typename T>
T ListaEncadeada<T>::getPrimeiro() const {
    if (primeiro == nullptr)
        throw std::runtime_error("Lista vazia");
    return primeiro->item;
}

template <typename T>
void ListaEncadeada<T>::removeInicio() {
    if (primeiro == nullptr)
        return;
    No<T>* temp = primeiro;
    primeiro = primeiro->prox;
    delete temp;
    --tamanho;
}

template <typename T>
void ListaEncadeada<T>::limpa() {
    No<T>* atual = primeiro;
    while (atual != nullptr) {
        No<T>* temp = atual;
        atual = atual->prox;
        delete temp;  // Remove o nó, mas não os objetos armazenados
    }
    primeiro = nullptr;  // A lista está vazia agora
    ultimo = nullptr;    // O último também é nullptr
    tamanho = 0;
}

#endif