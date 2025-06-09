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
    ultimo = nova;
    ++tamanho;
}

template<typename T>
void ListaEncadeada<T>::imprime() const {
    for (No<T>* atual = primeiro; atual != nullptr; atual = atual->prox) {
        std::cout << atual->item << " ";
    }
    std::cout << std::endl;
}

template<typename T>
int ListaEncadeada<T>::getTamanho() const {
    return tamanho;
}