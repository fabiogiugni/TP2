#include "fila.hpp"

template<typename T>
Fila<T>::Fila() : primeiro(nullptr), ultimo(nullptr){}

template<typename T>
Fila<T>::~Fila(){
    while (primeiro != nullptr){
        NoFila<T>* temp = primeiro;
        primeiro = primeiro->prox;
        delete temp;
    }
}

template<typename T>
void Fila<T>::Enfileira(const T& valor){
    NoFila<T>* novo = new NoFila<T>{valor, nullptr};
    if(ultimo != nullptr){
        ultimo->prox = novo;
    }else{
        primeiro = novo;
    }
    ultimo = novo;
}

template<typename T>
T Fila<T>::Desenfileira(){
    if(primeiro == nullptr) throw std::out_of_range("Fila vazia");
    T valor = primeiro->item;
    NoFila<T>* temp = primeiro;
    primeiro = primeiro->prox;
    if(primeiro == nullptr) ultimo = nullptr;
    delete temp;
    return valor;
}

template<typename T>
bool Fila<T>::vazia() const {
    return primeiro == nullptr;
}
