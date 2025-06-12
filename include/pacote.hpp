#ifndef PACOTE_HPP
#define PACOTE_HPP

#include "listaEncadeada.hpp"
#include "armazem.hpp"

class Pacote {
    public:
        Pacote(int tempo, int ident, int org, int dest);
        ~Pacote();
        int getOrigem();
        int getId();
        int getDestino();
        void registrarAlteracao(int tempo, int novoEstado, const std::string& descricao);
        void setRota(ListaEncadeada<Armazem> rota);
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
        Armazem destino;
    friend class Armazem;
    friend class Grafo;
    friend class Transporte;
};

#endif