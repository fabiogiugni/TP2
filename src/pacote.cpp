#include "Pacote.hpp"

Pacote::Pacote(){
    this->tamanho = 0;
    primeiro = nullptr;
    ultimo = nullptr;
}

Pacote::~Pacote(){
    while (primeiro != nullptr){
        No *temp = primeiro;
        primeiro = primeiro->prox;
        delete temp;
    }
}

void Pacote::insereInicio(int item){
    No *novo = new No{item, primeiro};
    primeiro = novo;
    if (ultimo == nullptr)
    {
        ultimo = novo;
    }
    ++tamanho;
}

void Pacote::insereFinal(int item){
    No *nova = new No{item, nullptr};
    if (ultimo != nullptr)
    {
        ultimo->prox = nova;
    }
    else
    {
        primeiro = nova;
    }
    ultimo = nova;
    ++tamanho;
}

void Pacote::imprime(){
    for (No* atual = primeiro; atual != nullptr; atual = atual->prox) {
        std::cout << atual->item << " ";  // imprime o valor do nó atual
    }
    std::cout << std::endl;  // quebra a linha após imprimir todos os vizinhos
}