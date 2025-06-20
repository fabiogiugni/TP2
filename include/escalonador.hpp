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
    void processaEventos();
    void processaEvento(int chave);
    Pacote* transformaChave(int chaveHeap);
    bool secoesVazias();
    void escalonaTransporte();
    void escalonaChegada(Pacote p);
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
