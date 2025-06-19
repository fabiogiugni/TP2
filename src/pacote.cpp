#include "pacote.hpp"

Pacote::Pacote() : chavePacote(-1), tempo(-1), id(-1), armazemOrigem(-1), armazemDestino(-1), tipoTransporte(-1) {}

Pacote::Pacote(int tempo, int ident, int org, int dest) : tempo(tempo), id(ident), armazemOrigem(org), armazemDestino(dest) ,tipoTransporte(1) {}

Pacote::~Pacote() {
    // Não precisa de ação manual aqui, pois a ListaEncadeada cuida da destruição
}

void Pacote::setRota(ListaEncadeada* novaRota) {
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
    std::cout << "Tempo de Chegada: " << tempo << std::endl;
    
    std::string estadoStr;
    switch (tipoTransporte) {
        case 1: estadoStr = "Não postado"; break;
        case 2: estadoStr = "Chegada escalonada a um armazém"; break;
        case 3: estadoStr = "Chegou a um armazém, mas não foi adicionado"; break;
        case 4: estadoStr = "Armazenado em armazém"; break;
        case 5: estadoStr = "Alocado para transporte"; break;
        case 6: estadoStr = "Entregue"; break;
        default: estadoStr = "Estado desconhecido"; break;
    }
    std::cout << "Estado do Pacote: " << estadoStr << std::endl;
    
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