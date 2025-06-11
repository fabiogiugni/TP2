#include "pacote.hpp"

Pacote::Pacote(int tempo, int ident, int org, int dest, Grafo mapa) : tempoChegada(tempo), id(ident), armazemOrigem(org), armazemDestino(dest) {

}

Pacote::~Pacote() {
    // Não precisa de ação manual aqui, pois a ListaEncadeada cuida da destruição
}

void Pacote::registrarAlteracao(int tempo, int novoEstado, const std::string& descricao) {
    // Criar a alteração
    Alteracao novaAlteracao = { tempo, novoEstado, descricao };

    // Adicionar a alteração à lista
    listaAlteracoes.insereFinal(novaAlteracao);
}