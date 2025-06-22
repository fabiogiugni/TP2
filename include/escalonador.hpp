#ifndef ESCALONADOR_HPP
#define ESCALONADOR_HPP

#include "pacote.hpp"
#include "armazem.hpp"
#include "heap.hpp"
#include <string>

class Escalonador {
public:
    Escalonador(int capacidadeTransporte, int latenciaTransporte, int intervaloTransporte, int custoRemocao, Pacote* pacotes, int numPacotes, Armazem* armazens, int numArmazens) ;
    ~Escalonador();
    void processaEventos(int tempoMin);
    bool secoesVazias();
    void escalonaTransporte(int tempo, int origem, int destino, int tempoMin);
    void escalonaChegada(int tempo, int id);
    int getIdArmazemDestino(int origem, int destino);

    void logEvento(int tempo, int idPacote, const std::string& acao, int origem, int destino);

    //fazer a funcao da chave do heap, fazer todos os transportes e depois a logica do escalonador em si.

    Heap heapEventos;  // Min-heap que armazena eventos
    int capacidadeTransporte;
    int latenciaTransporte;
    int intervaloTransporte;
    int custoRemocao;
    bool condicaoDeTermino; // Condição de término do sistema
    int numPac;
    Pacote* vetPac;
    int numArm;
    Armazem* vetArm;
};

#endif
