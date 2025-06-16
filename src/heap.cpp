#include "heap.hpp"
#include <stdexcept>  // Para exceções

Heap::Heap() {
    tamanho = 0;
    data = new Evento[100];  // Tamanho padrão (???????????)
}

Heap::Heap(int maxSize) {
    tamanho = 0;
    data = new Evento[maxSize];  // Agora a heap armazena Eventos
}

Heap::~Heap() {
    delete[] data;
}

bool Heap::Vazio() const {
    return (tamanho == 0);
}

int Heap::GetAncestral(int posicao) {
    return (posicao - 1) / 2;
}

int Heap::GetSucessorEsq(int posicao) {
    return (2 * posicao + 1);
}

int Heap::GetSucessorDir(int posicao) {
    return (2 * posicao + 2);
}

// Inserir um evento na heap
void Heap::Inserir(const Evento& e) {
    data[tamanho] = e;  // Armazena o evento na posição
    ++tamanho;
    HeapifyPorCima(tamanho - 1);  // Reorganiza a heap para manter a ordem
}

// Remover o evento com o menor tempo (mínimo)
Evento Heap::Remover() {
    if (Vazio()) {
        throw std::out_of_range("Heap vazia!");
    }

    Evento output = data[0];  // O evento com o menor tempo
    data[0] = data[tamanho - 1];  // Coloca o último evento no topo
    --tamanho;
    HeapifyPorBaixo(0);  // Reorganiza a heap para manter a ordem

    return output;
}

// Organizar o heap para cima (subir)
void Heap::HeapifyPorCima(int posicao) {
    while (posicao > 0 && data[posicao].tempoEvento < data[GetAncestral(posicao)].tempoEvento) {
        Evento temp = data[GetAncestral(posicao)];
        data[GetAncestral(posicao)] = data[posicao];
        data[posicao] = temp;
        posicao = GetAncestral(posicao);
    }
}

// Organizar o heap para baixo (descer)
void Heap::HeapifyPorBaixo(int posicao) {
    while (posicao < tamanho) {
        int esq = GetSucessorEsq(posicao);
        int dir = GetSucessorDir(posicao);

        int pai = posicao;
        
        // Verifica o menor entre o nó atual e seus filhos
        if (esq < tamanho && data[esq].tempoEvento < data[pai].tempoEvento) {
            pai = esq;
        }

        if (dir < tamanho && data[dir].tempoEvento < data[pai].tempoEvento) {
            pai = dir;
        }

        if (pai != posicao) {
            Evento temp = data[posicao];
            data[posicao] = data[pai];
            data[pai] = temp;
            posicao = pai;
        } else {
            break;  // O nó já está na posição correta
        }
    }
}
