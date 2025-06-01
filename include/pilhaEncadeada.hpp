#ifndef PILHAENCADEADAA_HPP
#define PILHAENCADEADAA_HPP

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


class PilhaEncadeada{
    public:
        PilhaEncadeada();
        ~PilhaEncadeada();
    
        void Empilha(TipoItem item);
        TipoItem Desempilha();
        void Limpa();
        bool Vazio();
    
    private:
        TipoCelula *topo;
        int tamanho;
};

#endif