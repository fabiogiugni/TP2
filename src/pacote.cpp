#include "pacote.hpp"

Pacote::Pacote() : tempoChegada(-1), id(-1), armazemOrigem(-1), armazemDestino(-1) {}

Pacote::Pacote(int tempo, int ident, int org, int dest) : tempoChegada(tempo), id(ident), armazemOrigem(org), armazemDestino(dest) {

}

Pacote::~Pacote() {
    // Não precisa de ação manual aqui, pois a ListaEncadeada cuida da destruição
}

void Pacote::setRota(ListaEncadeada novaRota){
    rota = novaRota;
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
    if (rota.getTamanho() > 0) {
        rota.removeInicio();  // Remove o armazém atual
    }
}

Armazem* Pacote::getProximoArmazem() const {
    if (rota.getTamanho() > 0) {
        return rota.getPrimeiro();  // Supondo que você tenha esse método na lista
    }
    throw std::runtime_error("Pacote sem próximo armazém: rota vazia.");
}

bool Pacote::chegouAoDestino() const {
    return rota.getTamanho() == 0;
}
