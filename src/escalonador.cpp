#include "escalonador.hpp"
#include <iomanip>  // para setw e setfill
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
        chave = vetPac[i].tempo*10000000 + vetPac[i].id*10 + 1;
        heapEventos.Inserir(chave);
    }
}

void Escalonador::escalonaTransporte(){
    long long int chave = 0;
    for(int i = 0; i < numArm; i++){
        for(int j = 0; j < vetArm[i].numVizinhos; j++){
            std::cout<<i<<std::endl;
            std::cout<<vetArm[i].vizinhos[j]<<std::endl;
            vetArm[i].getSecaoDestino(vetArm[i].vizinhos[j]).imprime();
            if(!vetArm[i].getSecaoDestino(vetArm[i].vizinhos[j]).Vazio()){
                chave = qtdeTransp*10000000 + vetArm[i].id*10000 + vetArm[i].vizinhos[j]*10 + 2;
                heapEventos.Inserir(chave);
            }
        }
    }
    qtdeTransp++;
}

void Escalonador::processaEventos(){
    int tempo_global = 0;
    escalonaTransporte(); //a princípio isso aqui está escalonando incorretamente pacotes no tempo 0 pq o meu vetor de armazens já está vindo com pacotes postados. vai mudar
    escalonaChegadaPacotes();
    while(!heapEventos.Vazio()){
        std::cout<<heapEventos.Remover()<<std::endl;
    }
    while(!heapEventos.Vazio() || !secoesVazias()){
        long long int chave = heapEventos.Remover();
        tempo_global = chave/10000000;
        if(chave%2 == 0){ //Se é evento de transporte
            int origem = (chave - tempo_global)/10000;
            int destino = (chave - tempo_global - origem)/10;
             if(!vetArm[origem].getSecaoDestino(vetArm[origem].vizinhos[destino]).Vazio()){
                PilhaEncadeada aux;
                int tamanho = vetArm[origem].getSecaoDestino(vetArm[origem].vizinhos[destino]).Tamanho();
                for(int i = 0; i < tamanho; i++){
                    tempo_global++;
                    aux.Empilha(vetArm[origem].getSecaoDestino(vetArm[origem].vizinhos[destino]).Desempilha());
                    logEvento(tempo_global,vetArm[origem].getSecaoDestino(vetArm[origem].vizinhos[destino]).Desempilha(),"removido de", origem, destino);
                }
                for(int i = 0; i < capacidadeTransporte || aux.Vazio(); i++){
                    vetArm[origem].getSecaoDestinoTransporte(vetArm[origem].vizinhos[destino]).Empilha(aux.Desempilha());
                    logEvento(tempo_global,aux.Desempilha(),"em transito de", origem, destino);
                }
                if(!aux.Vazio()){
                    while(!aux.Vazio()){
                        vetArm[origem].getSecaoDestino(vetArm[origem].vizinhos[destino]).Empilha(aux.Desempilha());
                        logEvento(tempo_global,aux.Desempilha(),"rearmazenado", origem, destino);
                    }
                }    
            }
            escalonaTransporte();
        }else{
            
        }
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

void Escalonador::logEvento(int tempo, int idPacote, const std::string& acao, int origem, int destino) {
    // Imprime o tempo e o ID do pacote
    std::cout << std::setw(7) << std::setfill('0') << tempo
              << " pacote " << std::setw(3) << std::setfill('0') << idPacote
              << " " << acao;  // Imprime a ação (armazenado, removido, etc.)

    // Adiciona informações dependendo do tipo de ação
    if (acao == "armazenado em" || acao == "removido de" || acao == "entregue em") {
        std::cout << " " << std::setw(3) << std::setfill('0') << origem;  // Imprime a origem (armazém)
        
        if (acao != "entregue em") {
            std::cout << " na secao " << std::setw(3) << std::setfill('0') << destino;  // Se não for "entregue", imprime a seção
        }
    } 
    else if (acao == "em transito de") {
        std::cout << " " << std::setw(3) << std::setfill('0') << origem
                  << " para " << std::setw(3) << std::setfill('0') << destino;  // Imprime de onde está indo para onde
    } 
    else if (acao == "rearmazenado") {
        std::cout << " em " << std::setw(3) << std::setfill('0') << origem
                  << " na secao " << std::setw(3) << std::setfill('0') << destino;  // Imprime a ação de rearmazenamento
    }

    // Finaliza a linha
    std::cout << std::endl;
}