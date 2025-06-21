#include "escalonador.hpp"
#include <iomanip>  // para setw e setfill

#include "escalonador.hpp"
#include <iostream>

// Construtor do escalonador
Escalonador::Escalonador(int capacidadeTransporte, int latenciaTransporte, int intervaloTransporte, int custoRemocao, Pacote* pacotes, int numPacotes, Armazem* armazens, int numArmazens) 
    : capacidadeTransporte(capacidadeTransporte), latenciaTransporte(latenciaTransporte), intervaloTransporte(intervaloTransporte),
    custoRemocao(custoRemocao), condicaoDeTermino(false), numPac(numPacotes), numArm(numArmazens),
    qtdeTransp(0){

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

bool Escalonador::secoesVazias(){
    for(int i = 0; i < numArm; i++){
        if(!vetArm[i].verificaSeTodasSecoesEstaoVazias()){
            return false;
        }
    }
    return true;
}

void Escalonador::escalonaChegadaPacotes(){
    long long int chave = 0;
    for(int i = 0; i < numPac; i++){
        chave = vetPac[i].tempo*10000000 + vetPac[i].id*10 + vetPac[i].tipoTransporte;
        heapEventos.Inserir(chave);
    }
}

void Escalonador::escalonaTransporte(){
    long long int chave = 0;
    for(int i = 0; i < numArm; i++){
        for(int j = 0; j < vetArm[i].numVizinhos; j++){
            std::cout<<i<<std::endl;
            std::cout<<vetArm[i].vizinhos[j]<<std::endl;
            if(!vetArm[i].getSecaoDestinoTransporte(vetArm[i].vizinhos[j]).Vazio()){
                std::cout<<"chegou"<<std::endl;
                chave = qtdeTransp*10000000 + vetArm[i].id*10000 + vetArm[i].vizinhos[j];
                heapEventos.Inserir(chave);
            }
        }
    }
    qtdeTransp++;
}

void Escalonador::processaEventos(){
    int tempo_global = 0;
    escalonaTransporte();
    escalonaChegadaPacotes();
    while(!heapEventos.Vazio()){
        std::cout<<heapEventos.Remover()<<std::endl;
    }
    while(!heapEventos.Vazio() || !secoesVazias()){
        long long int chave = heapEventos.Remover();
    }
}

Pacote* Escalonador::transformaChave(int chave){
    Pacote* p = nullptr;
    if(chave % 2 == 1){
        int id = (chave/10) % 1000000;
        int tempo_agora = chave/10000000;
        // Até tempo_agora não foi usado
        *p = vetPac[id];
    }else{
        int dest = ((chave % 10000) - 2) / 10;
        int orign = ((chave % 10000000) - dest - 2) / 1000;
        int tempo_agora = (chave/10000000);
        //de alguma forma acessar o pacote com essas características
    }
}