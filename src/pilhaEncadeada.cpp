#include "pilhaEncadeada.hpp"
#include <stdexcept>  // Para lançar exceções

PilhaEncadeada::PilhaEncadeada() : topo(nullptr), tamanho(0) {}

PilhaEncadeada::~PilhaEncadeada() {
    Limpa();
}

void PilhaEncadeada::Empilha(const Pacote& item) {
    No<Pacote>* novo = new No<Pacote>;
    novo->item = item;
    novo->prox = topo;
    topo = novo;
    tamanho++;
}

bool PilhaEncadeada::removePacotePorId(int id) {
    PilhaEncadeada auxiliar;
    bool encontrado = false;

    // Desempilha até encontrar ou esvaziar
    while (!Vazio()) {
        Pacote topoAtual = Desempilha();
        if (topoAtual.getId() == id) {
            encontrado = true;  // Não empilha novamente
            break;
        }
        auxiliar.Empilha(topoAtual);
    }

    // Reempilha os outros na pilha original
    while (!auxiliar.Vazio()) {
        Empilha(auxiliar.Desempilha());
    }

    return encontrado;
}


Pacote PilhaEncadeada::Desempilha() {
    if (Vazio()) {
        throw std::runtime_error("Erro: tentativa de desempilhar de uma pilha vazia.");
    }

    No<Pacote>* temp = topo;
    Pacote itemRemovido = temp->item;
    topo = topo->prox;
    delete temp;
    tamanho--;

    return itemRemovido;
}

void PilhaEncadeada::Limpa() {
    while (!Vazio()) {
        Desempilha();
    }
}

bool PilhaEncadeada::Vazio() const {
    return topo == nullptr;
}
