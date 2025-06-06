#ifndef ARMAZEM_HPP
#define ARMAZEM_HPP

#include "pacote.hpp"
#include "graph.hpp"

class Armazem{
    public:
        Armazem();
        ~Armazem();
    
    private:
        Grafo mapaArmazens;
        struct Alteracao {
            int tempo;          // instante da alteração
            int novoEstado;     // novo estado do pacote
        };
        ListaEncadeada<Alteracao> listaAlteracoes;
};

#endif