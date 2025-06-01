#ifndef ARMAZEM_HPP
#define ARMAZEM_HPP

#include "pacote.hpp"


class TipoCelula{
    public:
        TipoCelula(){
            item.SetChave(-1); //pacote
            prox = NULL;
        };
    private:
        TipoItem item; //pacote
        TipoCelula *prox;

    friend class PilhaEncadeada;
};


class Armazem{
    public:
        Armazem();
        ~Armazem();
    
        void Empilha(Pacote item);
        Pacote Desempilha();
        void Limpa();
        bool Vazio();
    
    private:
        Pacote *topo;
        int tamanho;
};

#endif