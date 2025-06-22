#include "armazem.hpp"
#include <iostream>
#include <stdexcept>

Armazem::Armazem() : id(0), numVizinhos(0), vizinhos(nullptr), pilhasPacotes(nullptr),pilhasTransporte(nullptr) {}

Armazem::Armazem(int id) : id(id), numVizinhos(0), vizinhos(nullptr), pilhasPacotes(nullptr),pilhasTransporte(nullptr) {}

Armazem::~Armazem() {
    // Desalocação de memória
    delete[] vizinhos;          // Libera o vetor de vizinhos
    delete[] pilhasPacotes;     // Libera o vetor de pilhas de pacotes
    delete[] pilhasTransporte;  // Libera o vetor de pilhas de transporte
}

int Armazem::getId() {
    return id;
}

void Armazem::setId(int id) {
    this->id = id;
}

PilhaEncadeada& Armazem::getSecaoDestino(int vizinhoId) {
    for (int i = 0; i < numVizinhos; i++) {
        if (vizinhos[i] == vizinhoId) {
            return pilhasPacotes[i];
        }
    }
    throw std::invalid_argument("Vizinho não encontrado em getSecaoDestino.");
}

PilhaEncadeada& Armazem::getSecaoDestinoTransporte(int vizinhoId) {
    for (int i = 0; i < numVizinhos; i++) {
        if (vizinhos[i] == vizinhoId) {
            return pilhasTransporte[i];
        }
    }
    throw std::invalid_argument("Vizinho não encontrado em getSecaoDestinoTransporte.");
}

void Armazem::inserePacote(Pacote p) {
    PilhaEncadeada& secao = getSecaoDestino(p.getProximoArmazem());  // Obtém a pilha para o destino do pacote
    std::cout << "Inserindo pacote " << p.getId() << " no armazém " << getId() << std::endl;
    secao.Empilha(p.getId());  // Empilha o pacote na seção correspondente
}

void Armazem::inserePacoteTransporte(Pacote p, int vizinhoId) {
    PilhaEncadeada& secaoTransporte = getSecaoDestinoTransporte(vizinhoId);  // Obtém a pilha de transporte para o vizinho
    secaoTransporte.Empilha(p.getId());  // Empilha o pacote na pilha de transporte
}


void Armazem::removerPacote(int vizinhoId, int pacoteId) {
    PilhaEncadeada& secao = getSecaoDestino(vizinhoId);  // Obtém a pilha para o vizinho
    secao.removePorId(pacoteId);  // Remove o pacote pela ID
}

bool Armazem::temPacotes(int vizinhoId) {
    PilhaEncadeada& secao = getSecaoDestino(vizinhoId);  // Obtém a pilha para o vizinho
    return !secao.Vazio();  // Verifica se a pilha de pacotes está vazia
}

int Armazem::quantidadePacotes(int vizinhoId) {
    PilhaEncadeada& secao = getSecaoDestino(vizinhoId);  // Obtém a pilha para o vizinho
    return secao.Tamanho();  // Retorna o número de pacotes na pilha
}

void Armazem::esvaziarSecao(int vizinhoId) {
    PilhaEncadeada& secao = getSecaoDestino(vizinhoId);  // Obtém a pilha para o vizinho
    secao.Limpa();  // Limpa a pilha de pacotes
}

void Armazem::visualizarPacotes(int vizinhoId) {
    PilhaEncadeada& secao = getSecaoDestino(vizinhoId);  // Obtém a pilha para o vizinho
    std::cout<<"imprimindo pilha para o vizinho:"<<vizinhoId<<std::endl;
    secao.imprime();  // Exibe os pacotes da pilha
}

void Armazem::adicionarVizinho(int idVizinho) {
    // Aumenta o número de vizinhos
    int* novosVizinhos = new int[numVizinhos + 1]; 
    PilhaEncadeada* novasPilhas = new PilhaEncadeada[numVizinhos + 1];
    PilhaEncadeada* novasPilhasTransporte = new PilhaEncadeada[numVizinhos + 1];  // Aloca memória para pilhas de transporte

    // Copia os vizinhos e as pilhas antigas
    for (int i = 0; i < numVizinhos; i++) {
        novosVizinhos[i] = vizinhos[i];
        novasPilhas[i] = pilhasPacotes[i];
        novasPilhasTransporte[i] = pilhasTransporte[i];  // Copia as pilhas de transporte
    }

    // Adiciona o novo vizinho
    novosVizinhos[numVizinhos] = idVizinho;
    novasPilhas[numVizinhos] = PilhaEncadeada();  // Nova pilha para o novo vizinho
    novasPilhasTransporte[numVizinhos] = PilhaEncadeada();  // Nova pilha de transporte para o novo vizinho

    // Desaloca a memória antiga
    delete[] vizinhos;
    delete[] pilhasPacotes;
    delete[] pilhasTransporte;  // Libera o antigo vetor de pilhas de transporte

    // Atualiza os ponteiros para os novos arrays
    vizinhos = novosVizinhos;
    pilhasPacotes = novasPilhas;
    pilhasTransporte = novasPilhasTransporte;  // Atualiza o ponteiro de pilhas de transporte
    numVizinhos++;  // Aumenta o número de vizinhos
}

void Armazem::imprimeVizinhos() const {
    std::cout << "Vizinhos do Armazem " << id << ": ";
    if (numVizinhos == 0) {
        std::cout << "Nenhum vizinho encontrado." << std::endl;
        return;
    }

    for (int i = 0; i < numVizinhos; i++) {
        std::cout << vizinhos[i] << " ";  // Imprime o ID do vizinho
    }
    std::cout << std::endl;  // Quebra a linha após listar todos os vizinhos

}

bool Armazem::verificaSeTodasSecoesEstaoVazias() {
    // Percorre todos os vizinhos
    for (int i = 0; i < numVizinhos; i++) {
        // Obtém a pilha de pacotes para o vizinho atual
        PilhaEncadeada& secao1 = getSecaoDestino(vizinhos[i]);
        
        // Se a pilha de pacotes para este vizinho não estiver vazia, retorna false
        if (!secao1.Vazio()) {
            return false;
        }

        PilhaEncadeada& secao2 = getSecaoDestinoTransporte(vizinhos[i]);
        
        // Se a pilha de pacotes para este vizinho não estiver vazia, retorna false
        if (!secao2.Vazio()) {
            return false;
        }
    }
    
    // Se todas as pilhas de pacotes para os vizinhos estiverem vazias, retorna true
    return true;
}
