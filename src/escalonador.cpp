// Dentro de escalonador.cpp
#include <iomanip>  // para setw e setfill
#include <iostream>
#include "escalonador.hpp"

void Escalonador::processarEventos() {
    while (!heapEventos.Vazio()) {
        Evento eventoAtual = heapEventos.Remover();
        relogioGlobal = eventoAtual.tempoEvento;

        switch (eventoAtual.tipoEvento) {
            case 1:
                processarTransporte(eventoAtual);
                break;
            case 2:
                processarChegada(eventoAtual);
                break;
            default:
                std::cerr << "Tipo de evento desconhecido." << std::endl;
        }
    }
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
