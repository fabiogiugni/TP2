#ifndef PACOTE_HPP
#define PACOTE_HPP

#include "listaEncadeada.hpp"
#include "armazem.hpp"

class Pacote {
    public:
        Pacote();
        Pacote(int tempo, int ident, int org, int dest);
        ~Pacote();
        int getOrigem();
        int getId();
        int getDestino();
        void setRota(ListaEncadeada<Armazem> novaRota);
        void avancarRota();  // Avança para o próximo armazém
        Armazem getProximoArmazem() const;  // Acessa o próximo armazém (sem remover)
        bool chegouAoDestino() const;       // Verifica se a rota acabou

    private:
        int tempoChegada;
        int id;
        int armazemOrigem;
        int armazemDestino;
        /* 
        1- não postado 
        2- chegada escalonada(já anotada) a um armazem 
        3- chegou a um armazem mas não foi add 
        4- armazenado em armazém 
        5- alocado para transporte 
        6- entregue
        */
        ListaEncadeada<Armazem> rota;
    friend class Armazem;
    friend class Grafo;
    friend class Transporte;
};

#endif