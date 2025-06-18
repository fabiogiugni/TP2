#include "fila.hpp"
#include <stdexcept>

Fila::Fila() : primeiro(nullptr), ultimo(nullptr) {}

Fila::~Fila() {
    while (primeiro != nullptr) {
        No* temp = primeiro;
        primeiro = primeiro->prox;
        delete temp;
    }
}

void Fila::Enfileira(int valor) {
    No* novo = new No{valor, nullptr};
    if (ultimo != nullptr) {
        ultimo->prox = novo;
    } else {
        primeiro = novo;
    }
    ultimo = novo;
}

int Fila::Desenfileira() {
    if (primeiro == nullptr) throw std::out_of_range("Fila vazia");

    int valor = primeiro->item;
    No* temp = primeiro;
    primeiro = primeiro->prox;
    if (primeiro == nullptr) {
        ultimo = nullptr;
    }
    delete temp;
    return valor;
}

bool Fila::vazia() const {
    return primeiro == nullptr;
}
