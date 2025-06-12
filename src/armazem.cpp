#include "armazem.hpp"

Armazem::Armazem(int id): id(id) {}

Armazem::~Armazem() {
    // A lista encadeada e as filas são gerenciadas automaticamente
}

int Armazem::getId(){
    return id;
}

void Armazem::adicionarPacoteDestino(int destino, const Pacote& pacote) {
    // Verificar se o destino já existe na lista
    DestinoSecao* secaoExistente = nullptr;
    DestinoSecao* atual = listaDestinoSecao.getPrimeiro();

    // Procurar pelo destino na lista
    while (atual != nullptr) {
        if (atual->destino == destino) {
            secaoExistente = atual;
            break;
        }
        atual = atual->prox;
    }

    // Se a seção de destino não existe, cria uma nova
    if (secaoExistente == nullptr) {
        DestinoSecao novaSecao;
        novaSecao.destino = destino;
        listaDestinoSecao.insereFinal(novaSecao);
        secaoExistente = listaDestinoSecao.getUltimo();
    }

    // Adiciona o pacote na fila do destino encontrado ou recém-criado
    secaoExistente->secao.Enfileira(pacote);
}

Fila<Pacote>& Armazem::getSecaoDestino(int destino) {
    // Procurar pelo destino na lista
    DestinoSecao* atual = listaDestinoSecao.getPrimeiro();
    while (atual != nullptr) {
        if (atual->destino == destino) {
            return atual->secao;  // Retorna a fila de pacotes do destino
        }
        atual = atual->prox;
    }

    // Se o destino não for encontrado, cria e retorna uma nova fila
    DestinoSecao novaSecao;
    novaSecao.destino = destino;
    listaDestinoSecao.insereFinal(novaSecao);
    return listaDestinoSecao.getUltimo()->secao;  // Retorna a nova fila
}
