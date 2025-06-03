#ifndef PACOTE_HPP
#define PACOTE_HPP

#include "listaEncadeada.hpp"

struct Alteracao {
    int tempo;          // instante da alteração
    int novoEstado;     // novo estado do pacote
};

class Pacote {
    public:
        Pacote();
        ~Pacote();

        void registrarAlteracao(const Alteracao& alt);
    private:
        int estado;
        ListaEncadeada<int> rota;
        ListaEncadeada<Alteracao> listaAlteracoes;
    friend class Armazem;
};

#endif