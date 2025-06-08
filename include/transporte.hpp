#ifndef TRANSPORTE_HPP
#define TRANSPORTE_HPP

#include "pacote.hpp"
#include "graph.hpp"

class Transporte{
    public:
        Transporte();
        ~Transporte();
    
    private:
        struct Alteracao {
            int tempo;          // instante da alteração
            int novoEstado;     // novo estado do pacote
        };
        ListaEncadeada<Alteracao> listaTransportes; //evento de transporte
};

#endif