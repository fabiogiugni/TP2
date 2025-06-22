#include "pacote.hpp"

Pacote::Pacote() : postado(false), tempoPostagem(-1), id(-1), armazemOrigem(-1), armazemDestino(-1), rota(nullptr) {}

Pacote::Pacote(const Pacote& outro) {
    postado = outro.postado;
    tempoPostagem = outro.tempoPostagem;
    id = outro.id;
    armazemOrigem = outro.armazemOrigem;
    armazemDestino = outro.armazemDestino;

    if (outro.rota) {
        rota = new ListaEncadeada();
        No* atual = outro.rota->primeiro;
        while (atual != nullptr) {
            rota->insereFinal(atual->item);
            atual = atual->prox;
        }
    } else {
        rota = nullptr;
    }
}

Pacote::Pacote(int tempo, int ident, int org, int dest) : postado(false), tempoPostagem(tempo), id(ident), armazemOrigem(org), armazemDestino(dest), rota(nullptr) {}

Pacote::~Pacote() {
    // Não precisa de ação manual aqui, pois a ListaEncadeada cuida da destruição
    delete rota;
}

Pacote& Pacote::operator=(const Pacote& outro) {
    if (this != &outro) {
        delete rota;

        postado = outro.postado;
        tempoPostagem = outro.tempoPostagem;
        id = outro.id;
        armazemOrigem = outro.armazemOrigem;
        armazemDestino = outro.armazemDestino;

        if (outro.rota) {
            rota = new ListaEncadeada();
            No* atual = outro.rota->primeiro;
            while (atual != nullptr) {
                rota->insereFinal(atual->item);
                atual = atual->prox;
            }
        } else {
            rota = nullptr;
        }
    }
    return *this;
}

void Pacote::setRota(ListaEncadeada* novaRota) {
    delete rota;
    // Cria uma nova lista para garantir que seja uma cópia profunda
    ListaEncadeada* rotaCopia = new ListaEncadeada();  // Aloca uma nova lista
    No* atual = novaRota->primeiro;
    while (atual != nullptr) {
        rotaCopia->insereFinal(atual->item);  // Copia os elementos
        atual = atual->prox;
    }

    // Substitui a rota com a nova lista copiada
    rota = rotaCopia;
}

int Pacote::getId(){
    return id;
}

int Pacote::getOrigem(){
    return armazemOrigem;
}

int Pacote::getDestino(){
    return armazemDestino;
}

int Pacote::getTempoPostagem(){
    return tempoPostagem;
}

void Pacote::avancarRota() {
    if (rota->tamanho > 0) {
        rota->removeInicio();  // Remove o armazém atual
    }
}

int Pacote::getArmazemAtual() const {
    if (rota->tamanho > 0) {
        return rota->primeiro->item;  // Supondo que você tenha esse método na lista
    }
    throw std::runtime_error("Pacote sem próximo armazém: rota vazia.");
}

int Pacote::getProximoArmazem() const {
    if (rota->tamanho > 0) {
        return rota->primeiro->prox->item;  // Supondo que você tenha esse método na lista
    }
    throw std::runtime_error("Pacote sem próximo armazém: rota vazia.");
}

bool Pacote::chegouAoDestino() const {
    return rota->tamanho == 0;
}

// Método para imprimir as informações do pacote
void Pacote::imprimirPacote() const {
    std::cout << "Pacote ID: " << id << std::endl;
    std::cout << "Origem: Armazém " << armazemOrigem << std::endl;
    std::cout << "Destino: Armazém " << armazemDestino << std::endl;
    std::cout << "Tempo de Chegada: " << tempoPostagem << std::endl;
    
    // Imprimir a rota do pacote
    std::cout << "Rota do Pacote: ";
    if (rota->tamanho == 0) {
        std::cout << "Nenhum armazém na rota." << std::endl;
    } else {
        No* atual = rota->primeiro;
        while (atual != nullptr) {
            std::cout << atual->item << " ";  // Imprime o ID do armazém
            atual = atual->prox;
        }
        std::cout << std::endl;
    }
}