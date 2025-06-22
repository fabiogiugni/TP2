#include "escalonador.hpp"
#include <iomanip>  // para setw e setfill
#include <iostream>

// Construtor do escalonador
Escalonador::Escalonador(int capacidadeTransporte, int latenciaTransporte, int intervaloTransporte, int custoRemocao, Pacote* pacotes, int numPacotes, Armazem* armazens, int numArmazens) 
    : capacidadeTransporte(capacidadeTransporte), latenciaTransporte(latenciaTransporte), intervaloTransporte(intervaloTransporte),
    custoRemocao(custoRemocao), condicaoDeTermino(false), numPac(numPacotes), numArm(numArmazens){

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

    /*// Exibe as informações dos pacotes e armazéns (depuração)
    for (int i = 0; i < numPacotes; i++) {
        vetPac[i].imprimirPacote();
    }

    for (int i = 0; i < numArmazens; i++) {
        vetArm[i].imprimeVizinhos();
    }*/
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

void Escalonador::escalonaChegada(int tempo, int id){
    __uint128_t  chave = 0;
    chave += (__uint128_t)tempo*10000000;
    chave += (__uint128_t)id * 10;
    chave += 1;
    heapEventos.Inserir(chave);
}

int Escalonador::getIdArmazemDestino(int origem, int destino){
    int i;
    for(i = 0; i < vetArm[origem].numVizinhos; i++){
        if(vetArm[origem].vizinhos[i] == destino){
            return i;
        }
    }
    throw std::invalid_argument("Vizinho não encontrado em getIdArmazemDestino.");
}

void Escalonador::escalonaTransporte(int tempo, int origem, int destino, int tempoMin){
    __uint128_t  chave = 0;
    tempo = (tempo/intervaloTransporte)*intervaloTransporte + tempoMin;
    chave += (__uint128_t)tempo*10000000;
    chave += (__uint128_t)vetArm[origem].id*10000;
    chave += (__uint128_t)vetArm[origem].vizinhos[destino]*10;
    chave += 2;
    heapEventos.Inserir(chave);
}

void Escalonador::processaEventos(int tempoMin){
    __uint128_t tempoGlobal = tempoMin;
    for(int origem = 0; origem < numArm; origem++){
        for(int destino = 0; destino < vetArm[origem].numVizinhos; destino++){
            escalonaTransporte(tempoMin + intervaloTransporte, origem, destino, tempoMin);
        }
    }
    for(int i = 0; i < numPac; i++){
        escalonaChegada(vetPac[i].tempoPostagem,vetPac[i].id);
    }
    do{
        __uint128_t  chave = heapEventos.Remover();
        tempoGlobal = chave/10000000;
        /*__uint128_t  copia = chave;   PARA DEBUGAR
        std::string str;
        while (copia > 0) {
            str = char('0' + (copia % 10)) + str;
            copia /= 10;
        }
        std::cout << str << std::endl;*/
        if(chave % 2 == 0){ //Se é evento de transporte
            int origem = (chave - tempoGlobal*10000000)/10000;
            int destino = (chave - tempoGlobal*10000000 - origem*10000)/10;
             if(!vetArm[origem].getSecaoDestino(destino).Vazio()){
                PilhaEncadeada aux;
                int tamanho = vetArm[origem].getSecaoDestino(destino).Tamanho();
                for(int i = 0; i < tamanho; i++){
                    tempoGlobal += custoRemocao;
                    int temp = vetArm[origem].getSecaoDestino(destino).Desempilha();
                    aux.Empilha(temp);
                    logEvento(tempoGlobal,temp,"removido de", origem, destino);
                }
                for(int i = 0; i < capacidadeTransporte && !aux.Vazio(); i++){
                    int idTemp = aux.Desempilha();
                    vetArm[origem].getSecaoDestinoTransporte(destino).Empilha(idTemp);
                    logEvento(tempoGlobal,idTemp,"em transito de", origem, destino);
                    escalonaChegada(tempoGlobal + latenciaTransporte, idTemp);
                }
                while(!aux.Vazio()){
                    int tpTemp = aux.Desempilha();
                    vetArm[origem].getSecaoDestino(destino).Empilha(tpTemp);
                    logEvento(tempoGlobal,tpTemp,"rearmazenado", origem, destino);
                }
            }
            int destinoCorrigido = getIdArmazemDestino(origem,destino);
            escalonaTransporte(tempoGlobal + intervaloTransporte, origem, destinoCorrigido, tempoMin);
        }else{
            tempoGlobal = chave/10000000;
            int id = (chave - tempoGlobal*10000000)/10;
            if((vetPac[id].getProximoArmazem() == vetPac[id].armazemDestino) && (vetPac[id].postado == true)){
                PilhaEncadeada aux;
                for(int i = 0; (vetArm[vetPac[id].getArmazemAtual()].getSecaoDestinoTransporte(vetPac[id].getProximoArmazem()).Tamanho() != 0) &&
                (i < vetArm[vetPac[id].getArmazemAtual()].getSecaoDestinoTransporte(vetPac[id].getProximoArmazem()).Tamanho() - 1); i++){
                    aux.Empilha(vetArm[vetPac[id].getArmazemAtual()].getSecaoDestinoTransporte(vetPac[id].getProximoArmazem()).Desempilha());
                }
                vetArm[vetPac[id].getArmazemAtual()].getSecaoDestinoTransporte(vetPac[id].getProximoArmazem()).Desempilha();
                logEvento(tempoGlobal,id,"entregue em", vetPac[id].armazemDestino, vetPac[id].armazemDestino);
                for(int i = 0; i < aux.Tamanho(); i++){
                    vetArm[vetPac[id].getArmazemAtual()].getSecaoDestinoTransporte(vetPac[id].getProximoArmazem()).Empilha(aux.Desempilha());
                }
                vetPac[id].avancarRota();
            }else if(vetPac[id].postado == false){
                vetArm[vetPac[id].getArmazemAtual()].getSecaoDestino(vetPac[id].getProximoArmazem()).Empilha(vetPac[id].id);
                logEvento(tempoGlobal, vetPac[id].id, "armazenado em",vetPac[id].armazemOrigem, vetPac[id].getProximoArmazem());
                vetPac[id].postado = true;
            }else{
                PilhaEncadeada aux;
                for(int i = 0; (vetArm[vetPac[id].getArmazemAtual()].getSecaoDestinoTransporte(vetPac[id].getProximoArmazem()).Tamanho() != 0) &&
                (i < vetArm[vetPac[id].getArmazemAtual()].getSecaoDestinoTransporte(vetPac[id].getProximoArmazem()).Tamanho() - 1); i++){
                    aux.Empilha(vetArm[vetPac[id].getArmazemAtual()].getSecaoDestinoTransporte(vetPac[id].getProximoArmazem()).Desempilha()); 
                }
                vetArm[vetPac[id].getArmazemAtual()].getSecaoDestinoTransporte(vetPac[id].getProximoArmazem()).Desempilha();
                for(int i = 0; i < aux.Tamanho() ; i++){
                    vetArm[vetPac[id].getArmazemAtual()].getSecaoDestinoTransporte(vetPac[id].getProximoArmazem()).Empilha(aux.Desempilha());
                }
                vetPac[id].avancarRota();
                vetArm[vetPac[id].getArmazemAtual()].getSecaoDestino(vetPac[id].getProximoArmazem()).Empilha(vetPac[id].id);
                logEvento(tempoGlobal,id,"armazenado em", vetPac[id].getArmazemAtual(), vetPac[id].getProximoArmazem());
            }
        }
    }while(!secoesVazias());
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