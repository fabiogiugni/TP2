#include "Pacote.hpp"

#include "pacote.hpp"

Pacote::Pacote() : estado(0), rota(), listaAlteracoes() {}

Pacote::~Pacote() {
    // Não precisa de ação manual aqui, pois a ListaEncadeada cuida da destruição
}

void Pacote::registrarAlteracao(int tempo, int novoEstado, const std::string& descricao) {
    // Criar a alteração
    Alteracao novaAlteracao = { tempo, novoEstado, descricao };

    // Adicionar a alteração à lista
    listaAlteracoes.insereFinal(novaAlteracao);
}