#include "armazem.hpp"

Armazem::Armazem(){
    topo = NULL;
    tamanho = 0;
}

Armazem::~Armazem(){
    Limpa();
}

void Armazem::Empilha(Pacote item){
    TipoCelula *nova;

    nova = new TipoCelula();
    nova->item = item;
    nova->prox = topo;
    topo = nova;
    tamanho++;
};


Pacote Armazem::Desempilha(){
    Pacote aux;
    TipoCelula *p;

    if(tamanho == 0)
        throw "O armazém está vazio!";

    aux = topo->item;
    p = topo;
    topo = topo->prox;
    delete p;
    tamanho--;

    return aux;
};


void Armazem::Limpa(){
    while(!Vazia())
    Desempilha();
}

bool Armazem::Vazio(){
    if(tamanho == 0){
        return 1;
    }else{
        return 0;
    }
}