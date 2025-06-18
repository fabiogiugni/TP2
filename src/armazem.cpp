#include "armazem.hpp"
#include <iostream>

Armazem::Armazem() : id(0), numVizinhos(0), vizinhos(nullptr), pilhasPacotes(nullptr) {}

Armazem::Armazem(int id) : id(id), numVizinhos(0), vizinhos(nullptr), pilhasPacotes(nullptr) {}

Armazem::~Armazem() {
    // Desalocação de memória
    delete[] vizinhos;  // Libera o vetor de vizinhos
    delete[] pilhasPacotes;  // Libera o vetor de pilhas
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
            return pilhasPacotes[i];  // Retorna a pilha de pacotes associada ao vizinho
        }
    }
    // Se não encontrar o vizinho, criamos uma nova pilha para ele
    return pilhasPacotes[0];  // Retorna a primeira pilha se o vizinho não for encontrado
}

void Armazem::inserePacote(Pacote p) {
    PilhaEncadeada& secao = getSecaoDestino(p.getDestino());  // Obtém a pilha para o destino do pacote
    secao.Empilha(p.getId());  // Empilha o pacote na seção correspondente
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
    secao.imprime();  // Exibe os pacotes da pilha
}

void Armazem::adicionarVizinho(int idVizinho) {
    // Aumenta o número de vizinhos
    int* novosVizinhos = new int[numVizinhos + 1]; 
    PilhaEncadeada* novasPilhas = new PilhaEncadeada[numVizinhos + 1];

    // Copia os vizinhos e as pilhas antigas
    for (int i = 0; i < numVizinhos; i++) {
        novosVizinhos[i] = vizinhos[i];
        novasPilhas[i] = pilhasPacotes[i];
    }

    // Adiciona o novo vizinho
    novosVizinhos[numVizinhos] = idVizinho;
    novasPilhas[numVizinhos] = PilhaEncadeada();  // Nova pilha para o novo vizinho

    // Desaloca a memória antiga
    delete[] vizinhos;
    delete[] pilhasPacotes;

    // Atualiza os ponteiros para os novos arrays
    vizinhos = novosVizinhos;
    pilhasPacotes = novasPilhas;
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