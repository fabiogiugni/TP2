#include "armazem.hpp"

PilhaEncadeada::PilhaEncadeada(){
    topo = NULL;
    tamanho = 0;
}

PilhaEncadeada::~PilhaEncadeada(){
    Limpa();
}

void PilhaEncadeada::Empilha(TipoItem item){
    TipoCelula *nova;

    nova = new TipoCelula();
    nova->item = item;
    nova->prox = topo;
    topo = nova;
    tamanho++;
};


TipoItem PilhaEncadeada::Desempilha(){
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


void PilhaEncadeada::Limpa(){
    while(!Vazia())
    Desempilha();
}

bool PilhaEncadeada::Vazio(){
    if(tamanho == 0){
        return 1;
    }else{
        return 0;
    }
}