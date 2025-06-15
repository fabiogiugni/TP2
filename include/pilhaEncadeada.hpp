#ifndef PILHAENCADEADAA_HPP
#define PILHAENCADEADAA_HPP

#include "pacote.hpp"
#include "listaEncadeada.hpp"


class PilhaEncadeada {
    public:
        PilhaEncadeada();
        ~PilhaEncadeada();

        void Empilha(const Pacote& item);
        Pacote Desempilha();
        void Limpa();
        bool Vazio() const;
        bool removePacotePorId(int id);  // remove pacote específico pelo ID


    private:
        No<Pacote>* topo;
        int tamanho;
friend class Transporte;
};

#endif
