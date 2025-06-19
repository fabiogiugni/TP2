#include "escalonador.hpp"
#include <iomanip>  // para setw e setfill

#include "escalonador.hpp"
#include <iostream>

// Construtor do escalonador
Escalonador::Escalonador(int capacidadeTransporte, int latenciaTransporte, int intervaloTransporte, Pacote* pacotes, int numPacotes, Armazem* armazens, int numArmazens) 
    : capacidadeTransporte(capacidadeTransporte), latenciaTransporte(latenciaTransporte), intervaloTransporte(intervaloTransporte),
    condicaoDeTermino(false), numPac(numPacotes), numArm(numArmazens){

    // Alocando e copiando os pacotes
    vetPac = new Pacote[numPacotes];
    for (int i = 0; i < numPacotes; i++) {
        vetPac[i] = pacotes[i];  // Copia os pacotes
    }

    // Alocando e copiando os armazéns
    vetArm = new Armazem[numArmazens];
    for (int i = 0; i < numArmazens; i++) {
        vetArm[i] = armazens[i];  // Copia os armazéns
    }

    // Exibe as informações dos pacotes e armazéns (depuração)
    for (int i = 0; i < numPacotes; i++) {
        vetPac[i].imprimirPacote();
    }

    for (int i = 0; i < numArmazens; i++) {
        vetArm[i].imprimeVizinhos();
    }
}

// Destruidor de escalonador
Escalonador::~Escalonador() {
    delete[] vetPac;
    delete[] vetArm;
}

Pacote* Escalonador::transformaChave(int chave){
    Pacote* p;
    if(chave % 2 == 1){
        int id = ((chave % 10000000) - 1) / 10;
        int tempo_agora = (chave - id - 1)/10000000;
        *p = vetPac[id];
    }else{
        
    }
}