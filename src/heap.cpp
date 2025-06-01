#include "heap.hpp"

Heap::Heap(int maxSize){
    tamanho = 0;
    data = new int[maxSize];
}

Heap::~Heap(){
    delete[] data;
}

bool Heap::Vazio(){
    return (tamanho == 0);
}

int Heap::GetAncestral(int posicao){
    return (posicao - 1)/2;
}
int Heap::GetSucessorEsq(int posicao){
    return (2*posicao + 1);
}
int Heap::GetSucessorDir(int posicao){
    return (2*posicao + 2);
}

void Heap::Inserir(int x){
    data[tamanho] = x;
    ++tamanho;
    HeapifyPorCima(tamanho-1);
}

int Heap::Remover(){
    if(Vazio()){
        return 0;
    }else{
        int output = data[0];
        data[0] = data[tamanho-1];
        --tamanho;
        HeapifyPorBaixo(0);
        return output;
    }
}

void Heap::HeapifyPorCima(int posicao){
    while(posicao > 0 && data[posicao] < data[GetAncestral(posicao)]){
        int temp = data[GetAncestral(posicao)];
        data[GetAncestral(posicao)] = data[posicao];
        data[posicao] = temp;
        posicao = GetAncestral(posicao);
    }
}

void Heap::HeapifyPorBaixo(int posicao) {
    // Enquanto houver filhos para comparar
    while (posicao < tamanho) {
        int esq = GetSucessorEsq(posicao);
        int dir = GetSucessorDir(posicao);

        int pai = posicao;
        
        if (esq < tamanho && data[esq] < data[pai]){
            pai = esq;
        }
        
        if (dir < tamanho && data[dir] < data[pai]){
            pai = dir;
        }
        
        if (pai != posicao){
            int temp = data[posicao];
            data[posicao] = data[pai];
            data[pai] = temp;
            posicao = pai; // continue o heapify na posição do maior filho
        } else {
            break; // se o nó já está na posição correta, interrompe o loop
        }
    }
}