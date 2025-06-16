// Dentro de escalonador.cpp
#include <iomanip>  // para setw e setfill
#include "escalonador.hpp"


Escalonador::Escalonador(int tempo) : relogioGlobal(tempo), condicaoDeTermino(false) {}

Escalonador::~Escalonador() {}

void Escalonador::escalonarTransporte(int tempoEvento, int origem, int destino) {
    Evento novoEvento;
    novoEvento.tempoEvento = tempoEvento;
    novoEvento.tipoEvento = 1; // Tipo 1 para transporte
    novoEvento.descricao = "Transporte de pacote de " + std::to_string(origem) + " para " + std::to_string(destino);

    heapEventos.Inserir(novoEvento);  // Insere o evento de transporte na heap
}

void Escalonador::escalonarChegada(int tempoEvento, int origem, int destino) {
    Evento novoEvento;
    novoEvento.tempoEvento = tempoEvento;
    novoEvento.tipoEvento = 2; // Tipo 2 para chegada de pacote
    novoEvento.descricao = "Chegada do pacote no armazém " + std::to_string(destino);

    heapEventos.Inserir(novoEvento);  // Insere o evento de chegada na heap
}

void Escalonador::processarTransporte(Evento& evento) {
    // Exemplo genérico
    int idPacote = /* obter id do pacote */ 0;
    int origem = /* armazém de origem */ 0;
    int destino = /* armazém de destino */ 0;

    std::cout << std::setw(7) << std::setfill('0') << relogioGlobal
              << " pacote " << std::setw(3) << std::setfill('0') << idPacote
              << " removido de " << std::setw(3) << origem
              << " na secao " << std::setw(3) << destino << std::endl;

    std::cout << std::setw(7) << std::setfill('0') << relogioGlobal + 1
              << " pacote " << std::setw(3) << std::setfill('0') << idPacote
              << " em transito de " << std::setw(3) << origem
              << " para " << std::setw(3) << destino << std::endl;
}

void Escalonador::processarChegada(Evento& evento) {
    // Exemplo genérico
    int idPacote = /* obter id do pacote */ 0;
    int destino = /* armazém de destino */ 0;
    bool foiEntregue = true;  // simula entrega final

    if (foiEntregue) {
        std::cout << std::setw(7) << std::setfill('0') << relogioGlobal
                  << " pacote " << std::setw(3) << std::setfill('0') << idPacote
                  << " entregue em " << std::setw(3) << destino << std::endl;
    } else {
        int proximaSecao = /* extrair próximo armazém */ 1;
        std::cout << std::setw(7) << std::setfill('0') << relogioGlobal
                  << " pacote " << std::setw(3) << std::setfill('0') << idPacote
                  << " armazenado em " << std::setw(3) << destino
                  << " na secao " << std::setw(3) << proximaSecao << std::endl;
    }
}
