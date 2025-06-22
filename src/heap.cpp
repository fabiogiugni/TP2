#include "heap.hpp"
#include <stdexcept>

// Construtor sem parâmetros - inicializa com tamanho 0 e vetor de dados de tamanho 0
Heap::Heap() {
    tamanho = 0;
    capacidade = 10;  // Define uma capacidade inicial padrão (pode ser alterado)
    data = new __uint128_t [capacidade];  // Inicializa o vetor de dados com a capacidade padrão
}

// Construtor com tamanho máximo especificado
Heap::Heap(int maxSize) {
    tamanho = 0;
    capacidade = maxSize;  // Define a capacidade máxima do heap
    data = new __uint128_t [capacidade];  // Aloca memória para o vetor de dados
}

// Destruidor - libera a memória alocada
Heap::~Heap() {
    delete[] data;  // Libera a memória do vetor de dados
}

// Verifica se o heap está vazio
bool Heap::Vazio() {
    return (tamanho == 0);  // Retorna verdadeiro se o tamanho for 0
}

// Retorna o índice do ancestral (pai) de um elemento
int Heap::GetAncestral(int posicao) {
    return (posicao - 1) / 2;  // Índice do pai no heap
}

// Retorna o índice do sucessor à esquerda de um elemento
int Heap::GetSucessorEsq(int posicao) {
    return (2 * posicao + 1);  // Índice do filho à esquerda no heap
}

// Retorna o índice do sucessor à direita de um elemento
int Heap::GetSucessorDir(int posicao) {
    return (2 * posicao + 2);  // Índice do filho à direita no heap
}

// Insere um elemento no heap
void Heap::Inserir(__uint128_t  x) {
    if(x < 0){
        throw std::invalid_argument("Valor inválido no heap.");
    }
    if (tamanho >= capacidade) {  // Verifica se há espaço suficiente
        // Realoca o vetor de dados se o heap estiver cheio
        __uint128_t * newData = new __uint128_t [capacidade * 2];  // Dobra a capacidade do vetor
        for (int i = 0; i < tamanho; i++) {
            newData[i] = data[i];  // Copia os dados antigos para o novo vetor
        }
        delete[] data;  // Libera a memória do vetor antigo
        data = newData;  // Atualiza o ponteiro para o novo vetor
        capacidade *= 2;  // Dobra a capacidade
    }

    data[tamanho] = x;  // Insere o novo elemento no final
    ++tamanho;  // Aumenta o tamanho
    HeapifyPorCima(tamanho - 1);  // Ajusta o heap para manter a propriedade do heap
}

// Remove o elemento de maior prioridade (no topo do heap)
__uint128_t  Heap::Remover() {
    if (Vazio()) {
        throw std::out_of_range("Heap está vazio");  // Lança exceção se o heap estiver vazio
    }
    
    __uint128_t  output = data[0];  // Armazena o topo (maior elemento)
    data[0] = data[tamanho - 1];  // Substitui o topo pelo último elemento
    --tamanho;  // Decrementa o tamanho
    HeapifyPorBaixo(0);  // Ajusta o heap para manter a propriedade do heap
    return output;  // Retorna o valor removido
}

// Reorganiza o heap para manter a propriedade do heap, subindo um elemento
void Heap::HeapifyPorCima(int posicao) {
    while (posicao > 0 && data[posicao] < data[GetAncestral(posicao)]) {
        // Troca o elemento com o pai se ele for menor
        __uint128_t  temp = data[GetAncestral(posicao)];
        data[GetAncestral(posicao)] = data[posicao];
        data[posicao] = temp;
        posicao = GetAncestral(posicao);  // Move para o pai
    }
}

// Reorganiza o heap para manter a propriedade do heap, descendo um elemento
void Heap::HeapifyPorBaixo(int posicao) {
    // Enquanto houver filhos para comparar
    while (posicao < tamanho) {
        int esq = GetSucessorEsq(posicao);  // Índice do filho esquerdo
        int dir = GetSucessorDir(posicao);  // Índice do filho direito

        int pai = posicao;

        // Verifica se o filho esquerdo é menor
        if (esq < tamanho && data[esq] < data[pai]) {
            pai = esq;
        }

        // Verifica se o filho direito é menor
        if (dir < tamanho && data[dir] < data[pai]) {
            pai = dir;
        }

        // Se algum filho for menor que o nó atual, realiza a troca
        if (pai != posicao) {
            __uint128_t  temp = data[posicao];
            data[posicao] = data[pai];
            data[pai] = temp;
            posicao = pai;  // Continue o Heapify na posição do filho trocado
        } else {
            break;  // Se o nó já está na posição correta, interrompe o loop
        }
    }
}
