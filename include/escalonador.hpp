#ifndef ESCALONADOR_HPP
#define ESCALONADOR_HPP

#include "pacote.hpp"
#include "armazem.hpp"
#include "heap.hpp"
#include <string>

class Escalonador {
public:
    Escalonador(int capacidadeTransporte, int latenciaTransporte, int intervaloTransporte, Pacote* pacotes, int numPacotes, Armazem* armazens, int numArmazens) ;
    ~Escalonador();
    void processaEvento();
    Pacote* transformaChave(int chaveHeap);
    //fazer a funcao da chave do heap, fazer todos os transportes e depois a logica do escalonador em si.
private:
    Heap heapEventos;  // Min-heap que armazena eventos
    int capacidadeTransporte;
    int latenciaTransporte;
    int intervaloTransporte;
    bool condicaoDeTermino; // Condição de término do sistema
    int numPac;
    Pacote* vetPac;
    int numArm;
    Armazem* vetArm;
};

#endif
