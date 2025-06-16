#include "armazem.hpp"

Armazem::Armazem() : id(-1) {}

Armazem::Armazem(int id): id(id) {}

Armazem::~Armazem() {
    // A lista encadeada e as filas são gerenciadas automaticamente
}

int Armazem::getId(){
    return id;
}

void Armazem::inserePacote(Pacote p) {
    int prox = p.getProximoArmazem().id;
    getSecaoDestino(prox).Empilha(p);
}


PilhaEncadeada<Pacote>& Armazem::getSecaoDestino(int destino) {
    for (No<DestinoSecao>* atual = listaDestinoSecao.primeiro; atual != nullptr; atual = atual->prox) {
        if (atual->item.destino == destino) {
            return atual->item.secao;
        }
    }

    // Se não encontrou, cria uma nova seção
    DestinoSecao nova;
    nova.destino = destino;
    listaDestinoSecao.insereFinal(nova);

    return listaDestinoSecao.ultimo->item.secao;
}

bool Armazem::removerPacote(int destino, int pacoteId) {
    // Percorre a lista de destinos e seções
    for (No<DestinoSecao>* atual = listaDestinoSecao.primeiro; atual != nullptr; atual = atual->prox) {
        if (atual->item.destino == destino) {
            // Encontrou a seção de destino. Agora remove o pacote da pilha (seção)
            return atual->item.secao.removePorId(pacoteId);  // Remove o pacote pela ID na pilha
        }
    }

    // Se não encontrou a seção, retorna false
    return false;
}

std::ostream& operator<<(std::ostream& os, const Armazem& armazem) {
    // Aqui você decide o que imprimir de Armazem. Exemplo:
    os << "Armazem ID: " << armazem.id;  // Imprimindo um atributo "id"
    return os;
}