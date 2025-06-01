#include "fila.hpp"

Fila::Fila() : primeiro(nullptr), ultimo(nullptr){}

Fila::~Fila(){
    while (primeiro != nullptr){
        NoFila* temp = primeiro;
        primeiro = primeiro->prox;
        delete temp;
    }
}

void Fila::Enfileira(int valor){
    NoFila* novo = new NoFila{valor,nullptr};
    if(ultimo != nullptr){
        ultimo->prox = novo;
    }else{
        primeiro = novo;
    }
    ultimo = novo;
}

int Fila::Desenfileira(){
    if(primeiro == nullptr) return -1;
    int valor = primeiro->item;
    NoFila* temp = primeiro;
    primeiro = primeiro->prox;
    if(primeiro == nullptr) ultimo = nullptr;
    delete temp;
    return valor;
}

